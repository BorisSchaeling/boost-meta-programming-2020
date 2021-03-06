#include <boost/mpl/vector.hpp>
#include <boost/mpl/integral_c.hpp>
#include <boost/mpl/find.hpp>
#include <boost/mpl/size.hpp>
#include <boost/mpl/less.hpp>
#include <boost/mpl/if.hpp>
#include <boost/mpl/int.hpp>
#include <string>

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
	using v = vector<std::string, int, bool>;

	constexpr int r1 = index_of<v, bool>::type::value;
	static_assert(r1 == 2);

	constexpr int r2 = index_of<v, double>::type::value;
	static_assert(r2 == -1);
}
