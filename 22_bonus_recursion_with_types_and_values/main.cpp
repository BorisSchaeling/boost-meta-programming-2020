#include <string>
#include <tuple>
#include <utility>
#include <iostream>
#include <cstddef>

template <typename T>
auto to_tuple(T&& object)
{
	auto&& [p1, p2, p3] = std::forward<T>(object);
	return std::tuple(p1, p2, p3);
}

template <typename Tuple, typename Callable, std::size_t I>
void call_with_tuple_element(const Tuple& tuple, Callable&& callable, std::index_sequence<I>)
{
	callable(std::get<I>(tuple));
}

template <typename Tuple, typename Callable, std::size_t I, std::size_t ...Is>
void call_with_tuple_element(const Tuple& tuple, Callable&& callable, std::index_sequence<I, Is...>)
{
	callable(std::get<I>(tuple));
	call_with_tuple_element(tuple, std::forward<Callable>(callable), std::index_sequence<Is...>());
}

template <typename Sequence, typename Callable>
void for_each(const Sequence& seq, Callable&& callable)
{
	auto tuple = to_tuple(seq);
	constexpr auto tuple_size = std::tuple_size_v<decltype(tuple)>;
	using indices = std::make_index_sequence<tuple_size>;
	call_with_tuple_element(tuple, std::forward<Callable>(callable), indices());
}

struct animal
{
	std::string name;
	int legs;
	bool has_tail;
};

int main()
{
	animal cat{ "cat", 4, true };
	for_each(cat, [](auto value) { std::cout << value << '\n'; });
}
