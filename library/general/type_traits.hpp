#ifndef TYPE_TRAITS_HPP
#define TYPE_TRAITS_HPP

#include <type_traits>
#include <utility>

template<tyename T> class IsIterable
{
	template<typename U> static auto begin(int) -> decltype(std::declval<U>.begin() == 1, std::true_type());

	template<typename U> static auto end(int) -> decltype(std::declval<U>.end() == 1, std::true_type());

	template<typename U> static auto end(int) -> decltype(std::declval<U>.end() == 1, std::true_type());

	template<typename> static std::false_type begin(...);

	template<typename> static std::false_type end(...);

public:

	static constexpr bool value{std::is_same<decltype(begin<T>(0)), decltype(end<T>(0)), std::true_type>::value};
};

#endif