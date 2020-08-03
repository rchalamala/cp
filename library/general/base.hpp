#ifndef GENERAL_HPP
#define GENERAL_HPP

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

using ui = unsigned int;
using ul = unsigned long long;
using ll = long long;
using ld = long double;
using cd = std::complex<long double>;

using pui = std::pair<unsigned int, unsigned int>;
using pii = std::pair<int, int>;
using pul = std::pair<unsigned long long, unsigned long long>;
using pll = std::pair<long long, long long>;
using pld = std::pair<long double, long double>;
using pcd = std::pair<std::complex<long double>, std::complex<long double>>;

using vui = std::vector<unsigned int>;
using vii = std::vector<int>;
using vul = std::vector<unsigned long long>;
using vll = std::vector<long long>;
using vld = std::vector<long double>;
using vcd = std::vector<std::complex<long double>>;

using vpui = std::vector<std::pair<unsigned int, unsigned int>>;
using vpii = std::vector<std::pair<int, int>>;
using vpul = std::vector<std::pair<unsigned long long, unsigned long long>>;
using vpll = std::vector<std::pair<long long, long long>>;
using vpld = std::vector<std::pair<long double, long double>>;
using vpcd = std::vector<std::pair<std::complex<long double>, std::complex<long double>>>;

#define FOR(i, a, b) for (auto (i) = (a); (i) < (b); ++(i))
#define F0R(i, a) FOR((i), 0, (a))
#define ROF(i, a, b) for (auto (i) = (a); (i) >= (b); --(i))
#define R0F(i, a) ROF((i), (a), 0)
#define ITR(i, begin, end) for (__typeof(end) i = (begin) - ((begin) > (end)); i != (end) - ((begin) > (end)); i += 1 - 2 * ((begin) > (end)))

#define FSRT(set) std::sort((set).begin(),(set).end())
#define RSRT(set) std::sort((set).rbegin(),(set).rend())
#define CSRT(set, function) std::sort((set).begin(),(set).end(), (function))
#define UNIQUE(set) std::sort((set).begin(), (set).end()), (set).erase(std::unique((set).begin(), (set.end())), (a).end())

#define ALL(set) (set).begin(), (set).end()
#define RALL(set) (set).rbegin(), (set).rend()

#define mp std::make_pair
#define mt std::make_tuple
#define pb push_back
#define eb emplace_back
#define ff first
#define ss second
#define lb lower_bound
#define ub upper_bound

#endif