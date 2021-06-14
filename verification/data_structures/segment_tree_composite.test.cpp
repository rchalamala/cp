#define PROBLEM "https://judge.yosupo.jp/problem/point_set_range_composite"

#include <cstddef>
#include <cstdint>
#include <iostream>
#include <vector>

#include "../../library/data_structures/segment_tree/segment_tree.hpp"
#include "../../library/data_structures/segment_tree/segment_tree_functions/segment_tree_composite.hpp"
#include "../../library/numerical/modulo.hpp"

int main()
{
	std::size_t n;
	std::int32_t q;
	std::cin >> n >> q;
	std::vector<CompositeNode<Modulo<std::integral_constant<std::decay_t<decltype(998244353)>, 998244353>>>> elements(n);
	for(std::size_t i = 0; i < n; ++i)
	{ std::cin >> elements[i].a >> elements[i].b; }
	SegmentTree<Composite<CompositeNode<Modulo<std::integral_constant<std::decay_t<decltype(998244353)>, 998244353>>>, false>> segmentTree(n);
	segmentTree.build(elements);
	while(q--)
	{
		bool queryType;
		std::cin >> queryType;
		if(queryType)
		{
			std::size_t l, r;
			std::uint64_t x;
			std::cin >> l >> r >> x;
			auto result = segmentTree.range(l, r - 1);
			std::cout << result.a * x + result.b << '\n';
		}
		else
		{
			std::size_t p;
			std::uint64_t c, d;
			std::cin >> p >> c >> d;
			segmentTree.change(p, p, c, d);
		}
	}
}
