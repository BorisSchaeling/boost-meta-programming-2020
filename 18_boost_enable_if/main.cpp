#include <boost/core/enable_if.hpp>
#include <type_traits>
#include <iostream>

template <typename T>
typename boost::disable_if_c<std::is_pointer_v<T>>::type print(T t)
{
	std::cout << t << '\n';
}

template <typename T>
typename boost::enable_if_c<std::is_pointer_v<T>>::type print(T t)
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
