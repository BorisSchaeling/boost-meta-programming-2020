template <int ...T>
struct list{};

constexpr int index_of(list<>, int value)
{
	return -1;
}

template <int T0>
constexpr int index_of(list<T0>, int value)
{
	if (value == T0) return 0;
	return -1;
}

template <int T0, int T1>
constexpr int index_of(list<T0, T1>, int value)
{
	if (value == T0) return 0;
	if (value == T1) return 1;
	return -1;
}

template <int T0, int T1, int T2>
constexpr int index_of(list<T0, T1, T2>, int value)
{
	if (value == T0) return 0;
	if (value == T1) return 1;
	if (value == T2) return 2;
	return -1;
}

template <int T0, int T1, int T2, int T3>
constexpr int index_of(list<T0, T1, T2, T3>, int value)
{
	if (value == T0) return 0;
	if (value == T1) return 1;
	if (value == T2) return 2;
	if (value == T3) return 3;
	return -1;
}

template <int T0, int T1, int T2, int T3, int T4>
constexpr int index_of(list<T0, T1, T2, T3, T4>, int value)
{
	if (value == T0) return 0;
	if (value == T1) return 1;
	if (value == T2) return 2;
	if (value == T3) return 3;
	if (value == T4) return 4;
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
