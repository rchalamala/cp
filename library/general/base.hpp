#ifndef BASE_HPP
#define BASE_HPP

#include <cassert>
#include <cctype>
#include <cerrno>
#include <cfloat>
#include <climits>
#include <clocale>
#include <cmath>
#include <csetjmp>
#include <csignal>
#include <cstdarg>
#include <cstddef>
#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <ctime>
#include <cwchar>
#include <cwctype>

#if __cplusplus >= 201103L

#include <cfenv>
#include <cinttypes>
#include <cstdint>
#include <cuchar>

#endif

#include <algorithm>
#include <bitset>
#include <complex>
#include <deque>
#include <exception>
#include <fstream>
#include <functional>
#include <iomanip>
#include <ios>
#include <iosfwd>
#include <iostream>
#include <istream>
#include <iterator>
#include <limits>
#include <list>
#include <locale>
#include <map>
#include <memory>
#include <new>
#include <numeric>
#include <ostream>
#include <queue>
#include <set>
#include <sstream>
#include <stack>
#include <stdexcept>
#include <streambuf>
#include <string>
#include <typeinfo>
#include <utility>
#include <valarray>
#include <vector>

#if __cplusplus >= 201103L

#include <typeindex>
#include <type_traits>
#include <chrono>
#include <initializer_list>
#include <tuple>
#include <scoped_allocator>
#include <cstdint>
#include <cinttypes>
#include <system_error>
#include <cuchar>
#include <array>
#include <forward_list>
#include <unordered_set>
#include <unordered_map>
#include <random>
#include <ratio>
#include <cfenv>
#include <regex>
#include <atomic>
#include <thread>
#include <mutex>
#include <future>
#include <condition_variable>

#endif

#if __cplusplus >= 201402L

#include <shared_mutex>

#endif

#if __cplusplus >= 201703L

#include <any>
#include <charconv>
#include <execution>
#include <filesystem>
#include <memory_resource>
#include <optional>
#include <string_view>
#include <variant>

#endif

#if __cplusplus >= 202002L
#include <barrier>
#include <bit>
#include <compare>
#include <concepts>
#include <coroutine>
#include <format>
#include <latch>
#include <numbers>
#include <ranges>
#inlclue <semaphore>
#include <source_location>
#include <span>
#include <stop_token>
#include <syncstream>
#include <version>
#endif

#ifdef __GNUC__

#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>
#include <ext/rope>

using namespace __gnu_pbds;
using namespace __gnu_cxx;

template<typename T> using ordered_set = __gnu_pbds::tree<T, __gnu_pbds::null_type, std::less<T>, __gnu_pbds::rb_tree_tag, __gnu_pbds::tree_order_statistics_node_update>;
template<typename T> using ordered_multiset = __gnu_pbds::tree<T, __gnu_pbds::null_type, std::less_equal<T>, __gnu_pbds::rb_tree_tag, __gnu_pbds::tree_order_statistics_node_update>;

#endif

#include "unused.hpp"

#define ALL(set) std::begin(set), std::end(set)
#define RALL(set) std::rbegin(set), std::rend(set)

#define mp std::make_pair
#define mt std::make_tuple
#define pb push_back
#define eb emplace_back
#define ff first
#define ss second
#define lb lower_bound
#define ub upper_bound

using ll = long long;
using pll = std::pair<long long, long long>;
using vll = std::vector<long long>;

using ull = unsigned long long;
using pull = std::pair<unsigned long long, unsigned long long>;
using vull = std::vector<unsigned long long>;

/*
#ifdef __SIZEOF_INT128__

using li = __int128;
using pli = std::pair<__int128, __int128>;
using vli = std::vector<__int128>;

using uli = unsigned __int128;
using puli = std::pair<unsigned __int128, unsigned __int128>;
using vuli = std::vector<unsigned __int128>;

#endif
*/

using ld = long double;
using pld = std::pair<long double, long double>;
using vld = std::vector<long double>;

#endif