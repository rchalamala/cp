#include "../../library/general/speed.hpp"

#define PROBLEM "https://www.hackerrank.com/challenges/subtrees-and-paths/problem"

#include <cstddef>
#include <cstdint>
#include <iostream>
#include <vector>

#include "../../library/graph/heavy_light_decomposition.hpp"
#include "../../library/data_structures/segment_tree/segment_tree.hpp"
#include "../../library/data_structures/segment_tree/segment_tree_functions/segment_tree_maximum.hpp"

int main()
{
	speed();
	std::size_t n;
	std::cin >> n;
	std::vector<std::vector<std::size_t>> graph(n);
	for(std::size_t i = 1; i < n; ++i)
	{
		std::size_t u, v;
		std::cin >> u >> v;
		--u;
		--v;
		graph[u].push_back(v);
		graph[v].push_back(u);
	}
	HeavyLightDecomposition<SegmentTree<Maximum<MaximumNode<std::int64_t>>>> hld(graph);
	std::int32_t q;
	std::cin >> q;
	while(q--)
	{
		std::string queryType;
		std::cin >> queryType;
		if(queryType == "add")
		{
			std::size_t t;
			std::int64_t value;
			std::cin >> t >> value;
			hld.update_sub_tree(t - 1, value);
		}
		else
		{
			std::size_t a, b;
			std::cin >> a >> b;
			std::cout << hld.range(a - 1, b - 1) << '\n';
		}
	}
}
