#include "../../library/general/input.hpp"
#include "../../library/general/output.hpp"
#include "../../library/general/speed.hpp"

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
	speed();
	std::size_t n;
	std::int_fast32_t q;
	read(std::cin, n, q);
	std::vector<std::uint_fast64_t> a(n);
	read(std::cin, a);
	std::vector<std::vector<std::size_t>> graph(n);
	for(std::size_t i = 1; i < n; ++i)
	{
		std::size_t p;
		read(std::cin, p);
		graph[i].push_back(p);
		graph[p].push_back(i);
	}
	HeavyLightDecomposition<std::uint_fast64_t, SegmentTree<Add<std::uint_fast64_t, AddNode<std::uint_fast64_t>>, AddNode<std::uint_fast64_t>>> hld(graph, a);
	while(q--)
	{
		bool queryType;
		read(std::cin, queryType);
		if(queryType)
		{
			std::size_t u;
			read(std::cin, u);
			printn(std::cout, hld.range(u));
		}
		else
		{
			std::size_t u;
			std::uint_fast64_t x;
			read(std::cin, u, x);
			hld.update_path(u, u, x);
		}
	}
}
