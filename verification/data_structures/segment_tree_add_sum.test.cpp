#include "../../library/general/input.hpp"
#include "../../library/general/output.hpp"
#include "../../library/general/speed.hpp"

#define PROBLEM "https://judge.yosupo.jp/problem/point_add_range_sum"

#include <cstdint>
#include <iostream>
#include <vector>

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
	SegmentTree<Add<std::uint_fast64_t, AddNode<std::uint_fast64_t>>, AddNode<std::uint_fast64_t>> segmentTree(n);
	segmentTree.build(a);
	while(q--)
	{
		bool queryType;
		read(std::cin, queryType);
		if(queryType)
		{
			std::size_t l, r;
			read(std::cin, l, r);
			printn(std::cout, segmentTree.range(l, r - 1));
		}
		else
		{
			std::size_t p;
			std::uint_fast64_t x;
			read(std::cin, p, x);
			segmentTree.change(p, p, x);
		}
	}
}
