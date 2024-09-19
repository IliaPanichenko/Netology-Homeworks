#include <iostream>
#include <fstream>
#include <exception>
#include <vector>
#include <string>
#include <map>
#include <sstream>

class parser_ini
{
private:
	std::map<std::string, std::map<std::string, std::string>> sections;
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
				size_t comment_pos = line.find(";");
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
	template<typename T>
	T get_value(const std::string& section_dot_var)
	{
		size_t dot_pos = section_dot_var.find(".");
		if (dot_pos == std::string::npos)
		{
			throw std::runtime_error("Invalid request format, expected 'section.var'");
		}
		std::string section = section_dot_var.substr(0, dot_pos);
		std::string var_va lue = section_dot_var.substr(dot_pos + 1);
		auto have_sections = sections.find(section);
		if (have_sections == sections.end())
		{
			throw std::runtime_error("There is no Section " + section);
		}
		auto var_it = have_sections->second.find(var_value);
		if (var_it == have_sections->second.end())
		{
			std::string suggestion = "Value not found. Available variables in section '" + section + "':";
			for (const auto& var : have_sections->second)
			{
				suggestion += "\n~" + var.first;
			}
			throw std::runtime_error(suggestion);
		}
		std::stringstream ss(var_it->second);
		T value;
		if (!(ss >> value))
		{
			throw std::runtime_error("Failed to convert value '" + var_it->second + "' to the required type.");
		}
		return value;
	}

};
int main()
{
    try 
	{
        parser_ini parser("parser.ini");

		double value1 = parser.get_value<double>("Section1.var1");
		std::cout << "Section1.var1 = " << value1 << "\n";

		std::string value2 = parser.get_value<std::string>("Section1.var2");
		std::cout << "Section1.var2 = " << value2 << "\n";

		int value3 = parser.get_value<int>("Section2.var1");
		std::cout << "Section2.var1 = " << value3 << "\n";

		std::string value4 = parser.get_value<std::string>("Section2.var2");
		std::cout << "Section2.var2 = " << value4 << "\n";

		std::string mode_value = parser.get_value<std::string>("Section4.var1");
		std::cout << "Section4.Mode = '" << mode_value << "'" << "\n";

    }
    catch (const std::exception& e) 
	{
        std::cerr << e.what() << "\n";
    }
	return 0;
}
