#include <type_traits>
#include <iostream>

struct default_tag{};

template <typename T>
void print_impl(T t, default_tag)
{
	std::cout << t << '\n';
}

struct pointer_tag{};

template <typename T>
void print_impl(T t, pointer_tag)
{
	std::cout << *t << '\n';
}

template <typename T>
void print(T t)
{
	using tag = std::conditional_t<std::is_pointer<T>::value, pointer_tag, default_tag>;
	print_impl(t, tag{});
}

int main()
{
	int i{1};
	print(i);

	int *p{&i};
	print(p);
}
