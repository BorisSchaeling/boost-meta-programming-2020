#include <array>
#include <algorithm>
#include <iterator>
#include <cstdint>
#include <cassert>

template <typename Sequence>
constexpr auto index_of(const Sequence& seq, int val)
{
	auto it = std::find(std::begin(seq), std::end(seq), val);
	return it != std::end(seq) ? std::distance(std::begin(seq), it) : -1;
}

int main()
{
	std::array<int, 5> a{ 5, 2, 3, 1, 4 };
	assert(index_of(a, 3) == 2);
	assert(index_of(a, 6) == -1);
}
