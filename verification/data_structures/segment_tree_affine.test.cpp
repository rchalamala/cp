#include "../../library/general/speed.hpp"

#define PROBLEM "https://judge.yosupo.jp/problem/range_affine_range_sum"

#include <cstddef>
#include <cstdint>
#include <iostream>
#include <vector>

#include "../../library/data_structures/segment_tree/segment_tree.hpp"
#include "../../library/data_structures/segment_tree/segment_tree_functions/segment_tree_affine.hpp"
#include "../../library/numerical/modular.hpp"

int main()
{
	speed();
	std::size_t n;
	std::int32_t q;
	std::cin >> n >> q;
	std::vector<std::uint64_t> a(n);
	for(auto& ai : a)
	{ std::cin >> ai; }
	SegmentTree<Affine<AffineNode<Modulo<std::integral_constant<std::decay_t<decltype(998244353)>, 998244353>>>>> segmentTree(n);
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
			std::size_t l, r;
			std::uint64_t b, c;
			std::cin >> l >> r >> b >> c;
			segmentTree.change(l, r - 1, b, c);
		}
	}
}
