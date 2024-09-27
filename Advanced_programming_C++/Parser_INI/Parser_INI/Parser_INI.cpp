#include <iostream>
#include <fstream>
#include <exception>
#include <vector>
#include <string>
#include <map>
#include <sstream>
#include <algorithm>

void trim(std::string& str)
{
	str.erase(str.begin(), std::find_if(str.begin(), str.end(), [](unsigned char ch)
		{
			return !std::isspace(ch);
		}));
	str.erase(std::find_if(str.rbegin(), str.rend(), [](unsigned char ch)
		{
			return !std::isspace(ch);
		}).base(), str.end());
}

std::string normalize_float_string(const std::string & str) 
{
	std::string normalized = str;
	std::replace(normalized.begin(), normalized.end(), ',', '.');
	return normalized;
}

class parser_ini
{
private:
	std::map<std::string, std::map<std::string, std::string>> sections;
public:
	parser_ini(const std::string& filename)
	{
		std::ifstream file(filename);
		if (!file.is_open())
		{
			throw std::runtime_error("File " + filename + " not found!\n");
		}
		std::string line;
		std::string current_section;
		int line_numbers = 0;
		while (std::getline(file, line))
		{
			line_numbers++;
			trim(line);
			if (line[0] == ';' || line.empty())
			{
				continue;
			}
			if (line[0] == '[' && line.back() == ']')
			{
				current_section = line.substr(1, line.size() - 2);
				trim(current_section);
				continue;
			}
			size_t equel_pos = line.find("=");
			if (equel_pos != std::string::npos)
			{
				std::string var_name = line.substr(0, equel_pos);
				std::string var_value = line.substr(equel_pos + 1);
				trim(var_name);
				trim(var_value);
				size_t comment_pos = var_value.find(";");
				if (comment_pos != std::string::npos)
				{
					var_value = var_value.substr(0, comment_pos);
					trim(var_value);
				}
				if (!current_section.empty())
				{
					sections[current_section][var_name] = var_value;
				}
				else
				{
					throw std::runtime_error("Syntax error: variable outside of section on line " + std::to_string(line_numbers));
				}
			}
			else
			{
				throw std::runtime_error("Syntax error: invalid line on line " + std::to_string(line_numbers));
			}
		}
	}
	std::string get_value_string (const std::string& section, const std::string& var)
	{
		auto have_sections = sections.find(section);
		if (have_sections == sections.end())
		{
			throw std::runtime_error("There is no " + section);
		}
		auto var_it = have_sections->second.find(var);
		if (var_it == have_sections->second.end())
		{
			std::string suggestion = "Value not found. Available variables in '" + section + "':";
			for (const auto& var : have_sections->second)
			{
				suggestion += "\n~" + var.first;
			}
			throw std::runtime_error(suggestion);
		}
		return var_it->second;
	}

	template <typename T>
	T get_value(const std::string& string_dot_var)
	{
		size_t dot_pos = string_dot_var.find(".");
		if (dot_pos == std::string::npos)
		{
			throw std::runtime_error("Invalid request format, expected 'section.var'");
		}
		std::string section = string_dot_var.substr(0, dot_pos);
		std::string var = string_dot_var.substr(dot_pos + 1);
		std::string string_value = get_value_string(section, var);
		string_value = normalize_float_string(string_value);
		T result{};
		if constexpr (std::is_same<int, T>::value)
		{
			result = std::stoi(string_value);
		}
		else if constexpr (std::is_same<double, T>::value)
		{
			result = std::stod(string_value);
		}
		else if constexpr (std::is_same<std::string, T>::value)
		{
			result = string_value;
		}
		else if constexpr (std::is_same<float, T>::value)
		{
			result = std::stof(string_value);
		}
		else
			static_assert(sizeof(T) == -1, "no implementation for this type!");
		return result;
	}

};
int main()
{
	try
	{
	parser_ini parser("parser.ini");

	std::cout << "string: " << parser.get_value<std::string>("Section1.var1") << std::endl;
	std::cout << "double: " << parser.get_value<double>("Section1.var1") << std::endl;
	std::cout << "int : " << parser.get_value<int>("Section1.var1") << std::endl;
	std::cout << "float: " << parser.get_value<float>("Section1.var4") << std::endl;
	std::cout << "string: " << parser.get_value<std::string>("Section1.var2") << std::endl;
	std::cout << "string: " << parser.get_value<std::string>("Section3.Mode") << std::endl;

	}
catch (const std::exception& e)
{
	std::cerr << e.what() << "\n";
}
return 0;
}
