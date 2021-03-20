#ifndef SEGMENT_TREE_HPP
#define SEGMENT_TREE_HPP

template<class F, class Node> class SegmentTree
{
public:
	F f;
private:
	const std::size_t size;
	std::vector<Node> tree;

	void propagate(const std::size_t& i, const std::size_t& treeLeft, const std::size_t& treeRight)
	{
		if(treeLeft != treeRight)
		{
			f.propagate_update(tree[i], tree[2 * i], tree[2 * i + 1], treeLeft, treeRight, tree.size() / 4);
			tree[i] = f.value(tree[2 * i], tree[2 * i + 1]);
		}
		else
		{
			f.propagate_update(tree[i], tree[i], tree[i], treeLeft, treeRight, tree.size() / 4);
		}
	}

	template<typename Iterable> void build(const std::size_t& i, const std::size_t& left, const std::size_t& right, const Iterable& elements)
	{
		if(left == right)
		{
			tree[i] = Node{elements[left]};
			return;
		}
		const std::size_t midpoint = left + (right - left) / 2;
		build(2 * i, left, midpoint, elements);
		build(2 * i + 1, midpoint + 1, right, elements);
		tree[i] = f.value(tree[2 * i], tree[2 * i + 1]);
	}

	template<typename... Arguments> void change(const std::size_t i, const std::size_t treeLeft, const std::size_t treeRight, const std::size_t& left, const std::size_t& right, const Arguments& ... rest)
	{
		if(left > treeRight || treeLeft > right) return;
		propagate(i, treeLeft, treeRight);
		if(left <= treeLeft && treeRight <= right)
		{
			f.change(tree[i], rest...);
			propagate(i, treeLeft, treeRight);
			return;
		}
		const std::size_t midpoint = treeLeft + (treeRight - treeLeft) / 2;
		change(2 * i, treeLeft, midpoint, left, right, rest...);
		change(2 * i + 1, midpoint + 1, treeRight, left, right, rest...);
		tree[i] = f.value(tree[2 * i], tree[2 * i + 1]);
	}

	Node range(const std::size_t& i, const std::size_t& treeLeft, const std::size_t& treeRight, const std::size_t& left, const std::size_t& right)
	{
		if(left > treeRight || treeLeft > right) return f.identity;
		propagate(i, treeLeft, treeRight);
		if(left <= treeLeft && treeRight <= right) return tree[i];
		const std::size_t midpoint = treeLeft + (treeRight - treeLeft) / 2;
		return f.value(range(2 * i, treeLeft, midpoint, left, right), range(2 * i + 1, midpoint + 1, treeRight, left, right));
	}

public:
	explicit SegmentTree(const std::size_t& u_size) : size{u_size} { tree.assign(4 * size, f.identity); }

	template<typename Iterable> void build(const Iterable& elements) { build(1, 0, elements.size() - 1, elements); }

	template<typename... Arguments> void change(const std::size_t& left, const std::size_t& right, const Arguments& ... rest) { change(1, 0, tree.size() / 4 - 1, left, right, rest...); }

	auto range(const std::size_t& left, const std::size_t& right) { return f.return_value(range(1, 0, tree.size() / 4 - 1, left, right)); }
};

#endif