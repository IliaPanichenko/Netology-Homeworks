#include <iostream>

template < typename T>
class My_unique_ptr
{
private:
	T* m_ptr;

public:
	My_unique_ptr(T* ptr = nullptr) : m_ptr(ptr) {};
	T& operator*() const
	{
		return *m_ptr;
	}
	T* operator->() const
	{
		return m_ptr;
	}
	T* release()
	{
		T* temp = m_ptr;
		m_ptr = nullptr;
		return temp;
	}
	My_unique_ptr(const My_unique_ptr& other) = delete;
	My_unique_ptr& operator=(const My_unique_ptr& other) = delete;
	~My_unique_ptr()
	{
		delete m_ptr;
	}
};
int main()
{
	My_unique_ptr<int> ptr(new int(20));
	std::cout << "Value: " << *ptr << "\n";
	*ptr = 15;
	std::cout << "Value after assignment: " << *ptr << "\n";
	int* rawPtr = ptr.release();
	std::cout << "Raw pointer: " << rawPtr << "\n";
	delete rawPtr;
	return 0;
}