#include <iostream>

template <typename T>
void print(T t)
{
	if constexpr(requires(T v) { -v; })
		std::cout << t << '\n';
	else if constexpr(requires(T v) { *v; })
		std::cout << *t << '\n';
}

int main()
{
	int i{ 1 };
	print(i);

	int* p{ &i };
	print(p);
}
