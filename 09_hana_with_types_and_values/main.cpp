#include <boost/hana.hpp>
#include <string>
#include <iostream>

using namespace boost::hana;

struct animal
{
	BOOST_HANA_DEFINE_STRUCT(animal,
		(std::string, name),
		(int, legs),
		(bool, has_tail)
	);
};

int main()
{
	tuple<std::string, int, bool> t{ "cat", 4, true };
	for_each(t, [](auto value) { std::cout << value << '\n'; });

	animal cat{ "cat", 4, true };
	for_each(cat, [](auto pair) { std::cout << boost::hana::second(pair) << '\n'; });
}
