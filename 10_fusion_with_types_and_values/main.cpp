#include <boost/fusion/tuple.hpp>
#include <boost/fusion/algorithm.hpp>
#include <boost/fusion/adapted.hpp>
#include <string>
#include <iostream>

using namespace boost::fusion;

BOOST_FUSION_DEFINE_STRUCT((), animal,
	(std::string, name)
	(int, legs)
	(bool, has_tail)
)

int main()
{
	tuple<std::string, int, bool> t{ "cat", 4, true };
	for_each(t, [](auto value) { std::cout << value << '\n'; });

	animal cat{ "cat", 4, true };
	for_each(cat, [](auto value) { std::cout << value << '\n'; });
}
