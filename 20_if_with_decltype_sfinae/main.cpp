#include <type_traits>
#include <iostream>

template <typename T>
auto print(T t) -> decltype(-t, void())
{
	std::cout << t << '\n';
}

template <typename T>
auto print(T t) -> decltype(*t, void())
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
