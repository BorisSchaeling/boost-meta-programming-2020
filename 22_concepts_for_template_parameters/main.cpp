#include <iostream>

template <typename T>
concept negatable = requires(T v) { -v; };

template <typename T>
concept dereferencable = requires(T v) { *v; };

template <negatable T>
void print(T t)
{
	std::cout << t << '\n';
}

template <dereferencable T>
void print(T t)
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
