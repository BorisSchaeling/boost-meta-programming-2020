#include <boost/hana.hpp>

using namespace boost::hana;

int main()
{
	constexpr auto t1 = make_tuple(int_c<5>, int_c<2>, int_c<3>, int_c<1>, int_c<4>);
	constexpr auto r1 = index_if(t1, equal.to(int_c<3>));
	static_assert(r1.value().value == 2);

	constexpr auto t2 = tuple_c<int, 5, 2, 3, 1, 4>;
	constexpr auto r2 = index_if(t2, equal.to(int_c<6>));
	static_assert(r2.value_or(-1) == -1);
}
