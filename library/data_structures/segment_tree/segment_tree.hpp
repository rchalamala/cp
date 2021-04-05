#ifndef SEGMENT_TREE_HPP
#define SEGMENT_TREE_HPP

#include <cstddef>
#include <vector>

template<class uF> class SegmentTree
{
public:
	using F = uF;
	using Node = typename F::Node;
	F f;
private:

	const std::size_t size;
	std::vector<Node> tree;

	void propagate(const std::size_t& i, const std::size_t& treeLeft, const std::size_t& treeRight, const std::size_t& left, const std::size_t& right)
	{
		if(treeLeft != treeRight)
		{ f.propagate_update(tree[i], tree[i << 1], tree[(i << 1) ^ 1], treeLeft, treeRight, left, right, size); }
		else
		{ f.propagate_update(tree[i], tree[i], tree[i], treeLeft, treeRight, left, right, size); }
	}

	template<typename Iterable> void build(const std::size_t& i, const std::size_t& left, const std::size_t& right, const Iterable& elements)
	{
		if(left == right)
		{
			tree[i] = Node{elements[left]};
			return;
		}
		const std::size_t midpoint = left + ((right - left) >> 1);
		build(i << 1, left, midpoint, elements);
		build((i << 1) ^ 1, midpoint + 1, right, elements);
		tree[i] = f.merge(tree[i << 1], tree[(i << 1) ^ 1]);
	}

	template<typename... Arguments> void change(const std::size_t& i, const std::size_t& treeLeft, const std::size_t& treeRight, const std::size_t& left, const std::size_t& right, const Arguments& ... rest)
	{
		propagate(i, treeLeft, treeRight, left, right);
		if(left > treeRight || treeLeft > right)
		{ return; }
		if(left <= treeLeft && treeRight <= right)
		{
			f.change(tree[i], treeLeft, treeRight, left, right, size, rest...);
			propagate(i, treeLeft, treeRight, left, right);
			return;
		}
		const std::size_t midpoint = treeLeft + ((treeRight - treeLeft) >> 1);
		change(i << 1, treeLeft, midpoint, left, right, rest...);
		change((i << 1) ^ 1, midpoint + 1, treeRight, left, right, rest...);
		tree[i] = f.merge(tree[i << 1], tree[(i << 1) ^ 1]);
	}

	Node range(const std::size_t& i, const std::size_t& treeLeft, const std::size_t& treeRight, const std::size_t& left, const std::size_t& right)
	{
		if(left > treeRight || treeLeft > right)
		{ return f.identity; }
		propagate(i, treeLeft, treeRight, left, right);
		if(left <= treeLeft && treeRight <= right)
		{ return tree[i]; }
		const std::size_t midpoint = treeLeft + ((treeRight - treeLeft) >> 1);
		return f.merge(range(i << 1, treeLeft, midpoint, left, right), range((i << 1) ^ 1, midpoint + 1, treeRight, left, right));
	}

public:
	explicit SegmentTree(const std::size_t& uSize) : size{uSize}
	{
		tree.assign(size << 2, Node{});
	}

	template<typename Iterable> void build(const Iterable& uElements)
	{
		build(1, 0, size - 1, uElements);
	}

	template<typename... Arguments> void change(const std::size_t& left, const std::size_t& right, const Arguments& ... rest)
	{
		change(1, 0, size - 1, left, right, rest...);
	}

	auto range(const std::size_t& left, const std::size_t& right)
	{
		return f.return_value(range(1, 0, size - 1, left, right));
	}
};

#endif