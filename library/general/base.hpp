#ifndef BASE_HPP
#define BASE_HPP

// Verification:
//

#include <algorithm>
#include <array>
#include <bitset>
#include <cassert>
#include <chrono>
#include <climits>
#include <cmath>
#include <complex>
#include <cstdarg>
#include <cstddef>
#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <ctime>
#include <deque>
#include <exception>
#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>
#include <ext/rope>
#include <forward_list>
#include <fstream>
#include <functional>
#include <initializer_list>
#include <iomanip>
#include <ios>
#include <iostream>
#include <iterator>
#include <limits>
#include <list>
#include <map>
#include <mutex>
#include <numeric>
#include <queue>
#include <random>
#include <set>
#include <sstream>
#include <stack>
#include <stdexcept>
#include <string>
#include <thread>
#include <tuple>
#include <typeinfo>
#include <unordered_map>
#include <unordered_set>
#include <utility>
#include <valarray>
#include <vector>

using namespace __gnu_pbds;
using namespace __gnu_cxx;

template<typename T> using ordered_set = __gnu_pbds::tree<T, __gnu_pbds::null_type, std::less<T>, __gnu_pbds::rb_tree_tag, __gnu_pbds::tree_order_statistics_node_update>;
template<typename T> using ordered_multiset = __gnu_pbds::tree<T, __gnu_pbds::null_type, std::less_equal<T>, __gnu_pbds::rb_tree_tag, __gnu_pbds::tree_order_statistics_node_update>;

using st = std::size_t;
using ui = std::uint32_t;
using ii = std::int32_t;
using ul = std::uint64_t;
using ll = std::int64_t;
using ld = long double;
using cd = std::complex<long double>;

using pst = std::pair<std::size_t, std::size_t>;
using pui = std::pair<std::uint32_t, std::uint32_t>;
using pii = std::pair<std::int32_t, std::int32_t>;
using pul = std::pair<std::uint64_t, std::uint64_t>;
using pll = std::pair<std::int64_t, std::int64_t>;
using pld = std::pair<long double, long double>;
using pcd = std::pair<std::complex<long double>, std::complex<long double>>;

using vst = std::vector<std::size_t>;
using vui = std::vector<std::uint32_t>;
using vii = std::vector<std::int32_t>;
using vul = std::vector<std::uint64_t>;
using vll = std::vector<std::int64_t>;
using vld = std::vector<long double>;
using vcd = std::vector<std::complex<long double>>;

using vvst = std::vector<std::vector<std::size_t>>;
using vvui = std::vector<std::vector<std::uint32_t>>;
using vvii = std::vector<std::vector<std::int32_t>>;
using vvul = std::vector<std::vector<std::uint64_t>>;
using vvll = std::vector<std::vector<std::int64_t>>;
using vvld = std::vector<std::vector<long double>>;
using vvcd = std::vector<std::vector<std::complex<long double>>>;

using vpst = std::vector<std::pair<std::size_t, std::size_t>>;
using vpui = std::vector<std::pair<std::uint32_t, std::uint32_t>>;
using vpii = std::vector<std::pair<std::int32_t, std::int32_t>>;
using vpul = std::vector<std::pair<std::uint64_t, std::uint64_t>>;
using vpll = std::vector<std::pair<std::int64_t, std::int64_t>>;
using vpld = std::vector<std::pair<long double, long double>>;
using vpcd = std::vector<std::pair<std::complex<long double>, std::complex<long double>>>;

#define FOR(i, a, b) for (auto (i) = (a); (i) < (b); ++(i))
#define F0R(i, a) FOR((i), 0, (a))
#define ROF(i, a, b) for (auto (i) = (a); (i) >= (b); --(i))
#define R0F(i, a) ROF((i), (a), 0)
#define ITR(i, begin, end) for (__typeof(end) i = (begin) - ((begin) > (end)); i != (end) - ((begin) > (end)); i += 1 - 2 * ((begin) > (end)))

#define FSRT(set) std::sort(std::begin(set), std::end(set))
#define RSRT(set) std::sort((set).rbegin(), (set).rend())
#define CSRT(set, function) std::sort(std::begin(set), std::end(set), (function))
#define UNIQUE(set) (set).erase(std::unique(std::begin(set), std::end(set)), std::end(set))
#define CLR(set, element) memset((set), (element), sizeof((set)))

#define ALL(set) std::begin(set), std::end(set)
#define RALL(set) std::rbegin(set), std::rend(set)

#define sc static_cast
#define sz(set) static_cast<std::int32_t>((set).size())

#define mp std::make_pair
#define mt std::make_tuple
#define pb push_back
#define eb emplace_back
#define ff first
#define ss second
#define lb lower_bound
#define ub upper_bound

#if __cplusplus >= 201402

#include <functional>
#include <utility>

namespace std
{
	template<class Fun> class y_combinator_result
	{
		Fun fun_;
	public:
		template<class T> explicit y_combinator_result(T&& fun): fun_(std::forward<T>(fun)) {}

		template<class ...Args> decltype(auto) operator()(Args&& ...args) { return fun_(std::ref(*this), std::forward<Args>(args)...); }
	};

	template<class Fun> decltype(auto) y_combinator(Fun&& fun) { return y_combinator_result<std::decay_t<Fun>>(std::forward<Fun>(fun)); }
}

#endif

#endif