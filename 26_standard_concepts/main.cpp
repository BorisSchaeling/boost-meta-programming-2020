#include <concepts>
#include <type_traits>
#include <iostream>

template <typename T>
concept negatable = std::integral<T>;

template <typename T>
concept dereferencable = std::is_pointer_v<T>;

void print(negatable auto t)
{
	std::cout << t << '\n';
}

void print(dereferencable auto t)
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
