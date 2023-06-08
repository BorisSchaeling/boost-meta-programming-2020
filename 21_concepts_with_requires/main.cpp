#include <iostream>

template <typename T>
concept negatable = requires(T v) { -v; };

template <typename T>
concept dereferencable = requires(T v) { *v; };

template <typename T>
void print(T t) requires negatable<T>
{
	std::cout << t << '\n';
}

template <typename T>
void print(T t) requires dereferencable<T>
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
