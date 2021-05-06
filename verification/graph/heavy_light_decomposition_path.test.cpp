#include "../../library/general/speed.hpp"

#define PROBLEM "https://judge.yosupo.jp/problem/vertex_add_path_sum"

#include <cstddef>
#include <cstdint>
#include <iostream>
#include <vector>

#include "../../library/graph/heavy_light_decomposition.hpp"
#include "../../library/data_structures/segment_tree/segment_tree.hpp"
#include "../../library/data_structures/segment_tree/segment_tree_functions/segment_tree_add.hpp"

int main()
{
	speed();
	std::size_t n;
	std::int32_t q;
	std::cin >> n >> q;
	std::vector <std::uint64_t> a(n);
	for(auto& ai : a)
	{ std::cin >> ai; }
	std::vector <std::vector<std::size_t>> graph(n);
	for(std::size_t i = 1; i < n; ++i)
	{
		std::size_t u, v;
		std::cin >> u >> v;
		graph[u].push_back(v);
		graph[v].push_back(u);
	}
	HeavyLightDecomposition<SegmentTree<Add<AddNode<std::uint64_t>>>> hld(graph);
	hld.build(a);
	while(q--)
	{
		bool queryType;
		std::cin >> queryType;
		if(queryType)
		{
			std::size_t u, v;
			std::cin >> u >> v;
			std::cout << hld.range(u, v) << '\n';
		}
		else
		{
			std::size_t p;
			std::uint64_t x;
			std::cin >> p >> x;
			hld.update_path(p, p, x);
		}
	}
}
