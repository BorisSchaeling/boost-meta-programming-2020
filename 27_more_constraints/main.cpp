#include <concepts>
#include <iostream>
#include <cstddef>

template <typename T>
concept negatable = requires(T v) { {-v} -> std::same_as<T>; };

template <typename T>
concept dereferencable = requires(T v) { {*v} -> std::convertible_to<std::size_t>; };

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
