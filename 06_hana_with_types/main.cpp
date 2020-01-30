#include <boost/hana.hpp>
#include <string>

using namespace boost::hana;

int main()
{
	auto t = make_tuple(type_c<std::string>, type_c<int>, type_c<bool>);

	auto r1 = index_if(t, equal.to(type_c<bool>));
	static_assert(r1.value().value == 2);

	auto r2 = index_if(t, equal.to(type_c<double>));
	static_assert(r2.value_or(-1) == -1);
}
