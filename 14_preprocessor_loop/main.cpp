#include <boost/preprocessor/cat.hpp>
#include <boost/preprocessor/punctuation/comma_if.hpp>
#include <boost/preprocessor/arithmetic/inc.hpp>
#include <boost/preprocessor/repetition/repeat.hpp>

template <int ...T>
struct list{};

constexpr int index_of(list<>, int)
{
	return -1;
}

#define INDEX_OF_TEMPLATE_PARAMETERS(z, n, text) BOOST_PP_COMMA_IF(n) BOOST_PP_CAT(text, n)

#define INDEX_OF_TEMPLATE(z, n, _) \
	template <BOOST_PP_REPEAT_ ## z(BOOST_PP_INC(n), INDEX_OF_TEMPLATE_PARAMETERS, int T)> \
	constexpr int index_of(list<BOOST_PP_REPEAT_ ## z(BOOST_PP_INC(n), INDEX_OF_TEMPLATE_PARAMETERS, T)>, int value) \
	{ \
		return value == BOOST_PP_CAT(T, n) ? n : index_of(list<BOOST_PP_REPEAT_ ## z(n, INDEX_OF_TEMPLATE_PARAMETERS, T)>{}, value); \
	}

BOOST_PP_REPEAT(5, INDEX_OF_TEMPLATE, nil)

int main()
{
	list<5, 2, 3, 1, 4> l;

	constexpr int r1 = index_of(l, 3);
	static_assert(r1 == 2);

	constexpr int r2 = index_of(l, 6);
	static_assert(r2 == -1);
}
