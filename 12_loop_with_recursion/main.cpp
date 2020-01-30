template <int ...T>
struct list{};

constexpr int index_of_impl(list<>, int, int)
{
	return -1;
}

template <int T, int ...U>
constexpr int index_of_impl(list<T, U...>, int value, int n)
{
	return value == T ? n : index_of_impl(list<U...>{}, value, n + 1);
}

template <int ...T>
constexpr int index_of(list<T...> l, int value)
{
	return index_of_impl(l, value, 0);
}

int main()
{
	list<5, 2, 3, 1, 4> l;

	constexpr int r1 = index_of(l, 3);
	static_assert(r1 == 2);

	constexpr int r2 = index_of(l, 6);
	static_assert(r2 == -1);
}
