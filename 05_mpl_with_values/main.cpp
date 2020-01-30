#include <boost/mpl/vector_c.hpp>
#include <boost/mpl/integral_c.hpp>
#include <boost/mpl/find.hpp>
#include <boost/mpl/size.hpp>
#include <boost/mpl/less.hpp>
#include <boost/mpl/if.hpp>
#include <boost/mpl/int.hpp>

using namespace boost::mpl;

template <typename Sequence, typename Value>
struct index_of
{
	using it = typename find<Sequence, Value>::type;
	using index = typename it::pos;
	using size = typename size<Sequence>::type;
	using index_smaller_than_size = typename less<index, size>::type;
	using type = typename if_<index_smaller_than_size, index, int_<-1>>::type;
};

int main()
{
	using v = vector_c<int, 5, 2, 3, 1, 4>;

	constexpr int r1 = index_of<v, integral_c<int, 3>>::type::value;
	static_assert(r1 == 2);

	constexpr int r2 = index_of<v, integral_c<int, 6>>::type::value;
	static_assert(r2 == -1);
}
