#include <boost/mp11/mpl.hpp>
#include <type_traits>

template <int I>
using int_ = std::integral_constant<int, I>;

using namespace boost::mp11;

template <typename Sequence, typename Value>
struct index_of_impl
{
	using index = mp_find<Sequence, Value>;
	using size = mp_size<Sequence>;
	using index_smaller_than_size = mp_less<index, size>;
	using type = mp_if<index_smaller_than_size, index, int_<-1>>;
};

template <typename Sequence, typename Value>
using index_of = typename index_of_impl<Sequence, Value>::type;

int main()
{
	using l = mp_list_c<int, 5, 2, 3, 1, 4>;

	constexpr int r1 = index_of<l, int_<3>>::value;
	static_assert(r1 == 2);

	constexpr int r2 = index_of<l, int_<6>>::value;
	static_assert(r2 == -1);
}
