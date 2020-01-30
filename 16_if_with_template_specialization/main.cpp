#include <type_traits>
#include <iostream>

template <typename T>
struct print_impl
{
	static void print(T t)
	{
		std::cout << t << '\n';
	}
};

template <typename T>
struct print_impl<T*>
{
	static void print(T *t)
	{
		std::cout << *t << '\n';
	}
};

template <typename T>
void print(T t)
{
	print_impl<T>::print(t);
}

int main()
{
	int i{ 1 };
	print(i);

	int* p{ &i };
	print(p);
}
