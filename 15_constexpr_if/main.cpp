#include <type_traits>
#include <iostream>

template <typename T>
void print(T t)
{
	if constexpr (std::is_pointer<T>::value)
		std::cout << *t << '\n';
	else
		std::cout << t << '\n';
}

int main()
{
	int i{1};
	print(i);

	int *p{&i};
	print(p);
}
