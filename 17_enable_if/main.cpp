#include <type_traits>
#include <iostream>

template <typename T>
std::enable_if_t<!std::is_pointer<T>::value> print(T t)
{
	std::cout << t << '\n';
}

template <typename T>
std::enable_if_t<std::is_pointer<T>::value> print(T t)
{
	std::cout << *t << '\n';
}

int main()
{
	int i{ 1 };
	print(i);

	int* p{ &i };
	print(p);
}
