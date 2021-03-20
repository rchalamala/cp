#ifndef DISTINCTELEMENTS_HPP
#define DISTINCTELEMENTS_HPP
/*
#include "base.h"
#include "input.h"
#include "output.h"

using namespace std;

constexpr long long MAXN __attribute__((unused)) =
	static_cast<long long>(2 * 1e5 + 1);
constexpr long long INF __attribute__((unused)) =
	static_cast<long long>(1e18 + 1);
constexpr long long MOD __attribute__((unused)) =
	static_cast<long long>(1e9 + 7);
constexpr long double EPS __attribute__((unused)) =
	static_cast<long double>(1e-7);

#include "../datastructures/bit.hpp"
#include "../graph/base/edges/bi_edge.hpp"
#include "../graph/base/graph.hpp"
#include "../numerical/compress.hpp"

class DistinctColors {
  void dfs(Graph<BiEdge>& graph, vector<pair<size_t, size_t>>& times,
		   ll& current, const size_t& i = 0, const size_t& parent = 0) {
	times[i].ff = ++current;
	for (const auto& neighbor : graph[i])
	  if (neighbor.to != parent) dfs(graph, times, current, neighbor.to, i);
	times[i].ss = current;
  }

 public:
  void solve(std::istream& in, std::ostream& out) {
	size_t n;
	read(in, n);
	vector<ll> c(n);
	read(in, c);
	auto total = compress(c);
	Graph<BiEdge> graph(n);
	for (size_t i = 0; i < n - 1; ++i) {
	  size_t a, b;
	  read(in, a, b);
	  graph.addEdge(a - 1, b - 1);
	}
	vector<pair<size_t, size_t>> euler(n);
	ll current = -1;
	dfs(graph, euler, current);
	vector<tuple<size_t, size_t, size_t>> queries;
	vector<ll> orderedC(n);
	for (size_t i = 0; i < n; ++i) {
	  queries.eb(euler[i].ss, euler[i].ff, i);
	  orderedC[euler[i].ff] = c[i];
	}
	FSRT(queries);
	c = orderedC;
	BIT<ll> bit(n);
	vector<ll> last(total, -1), answer(queries.size());
	size_t index = 0;
	for (size_t i = 0; i < n; ++i) {
	  if (last[c[i]] != -1) bit.update(last[c[i]], -1);
	  bit.update(last[c[i]] = i, 1);
	  while (index < n && get<0>(queries[index]) == i) {
		answer[get<2>(queries[index])] =
			bit.query(get<1>(queries[index]), get<0>(queries[index]));
		++index;
	  }
	}
	prints(out, answer);
  }
};
*/
#endif