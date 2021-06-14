#define PROBLEM "https://judge.yosupo.jp/problem/vertex_add_subtree_sum"

#include <cstddef>
#include <cstdint>
#include <iostream>
#include <vector>

#include "../../library/graph/heavy_light_decomposition.hpp"
#include "../../library/data_structures/segment_tree/segment_tree.hpp"
#include "../../library/data_structures/segment_tree/segment_tree_functions/segment_tree_add.hpp"

int main()
{
	std::size_t n;
	std::int32_t q;
	std::cin >> n >> q;
	std::vector <std::uint64_t> a(n);
	for(auto& ai : a)
	{ std::cin >> ai; }
	std::vector <std::vector<std::size_t>> graph(n);
	for(std::size_t i = 1; i < n; ++i)
	{
		std::size_t p;
		std::cin >> p;
		graph[i].push_back(p);
		graph[p].push_back(i);
	}
	HeavyLightDecomposition<SegmentTree<Add<AddNode<std::uint64_t>>>> hld(graph);
	hld.build(a);
	while(q--)
	{
		bool queryType;
		std::cin >> queryType;
		if(queryType)
		{
			std::size_t u;
			std::cin >> u;
			std::cout << hld.range(u) << '\n';
		}
		else
		{
			std::size_t u;
			std::uint64_t x;
			std::cin >> u >> x;
			hld.update_path(u, u, x);
		}
	}
}
