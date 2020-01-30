#include <initializer_list>

template <int...>
struct list{};

template <int ...T>
constexpr int index_of(list<T...>, int value)
{
	int index{};
	for (int i : { T... })
	{
		if (i == value)
			return index;
		++index;
	}
	return -1;
}

int main()
{
	list<5, 2, 3, 1, 4> l;

	constexpr int r1 = index_of(l, 3);
	static_assert(r1 == 2);

	constexpr int r2 = index_of(l, 6);
	static_assert(r2 == -1);
}
