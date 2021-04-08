#ifndef COMMON_TYPE_HPP
#define COMMON_TYPE_HPP

#include <algorithm>

template<typename T1, typename T2> std::common_type_t<T1, T2> static min(const T1& lhs, const T2& rhs) { return std::min(static_cast<std::common_type_t<T1, T2>>(lhs), static_cast<std::common_type_t<T1, T2>>(rhs)); }

template<typename T1, typename T2> std::common_type_t<T1, T2> static max(const T1& lhs, const T2& rhs) { return std::max(static_cast<std::common_type_t<T1, T2>>(lhs), static_cast<std::common_type_t<T1, T2>>(rhs)); }

#endif