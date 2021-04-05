#include "../../library/general/speed.hpp"

#define PROBLEM "https://judge.yosupo.jp/problem/point_add_range_sum"

#include <cstddef>
#include <cstdint>
#include <iostream>
#include <vector>

#include "../../library/data_structures/segment_tree/segment_tree.hpp"
#include "../../library/data_structures/segment_tree/segment_tree_functions/segment_tree_add.hpp"

int main()
{
	speed();
	std::size_t n;
	std::int32_t q;
	std::cin >> n >> q;
	std::vector<std::uint64_t> a(n);
	for(auto& ai : a)
	{ std::cin >> ai; }
	SegmentTree<Add<AddNode<std::uint64_t>>> segmentTree(n);
	segmentTree.build(a);
	while(q--)
	{
		bool queryType;
		std::cin >> queryType;
		if(queryType)
		{
			std::size_t l, r;
			std::cin >> l >> r;
			std::cout << segmentTree.range(l, r - 1) << '\n';
		}
		else
		{
			std::size_t p;
			std::uint64_t x;
			std::cin >> p >> x;
			segmentTree.change(p, p, x);
		}
	}
}
