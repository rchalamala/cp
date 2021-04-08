#ifndef SEGMENT_TREE_MAXIMUM_HPP
#define SEGMENT_TREE_MAXIMUM_HPP

#include <algorithm>
#include <cstddef>
#include <limits>
#include <type_traits>

#include "segment_tree_add.hpp"

template<typename uT, std::enable_if_t<std::is_arithmetic_v<uT>, bool> = true> struct MaximumNode : AddNode<uT>
{
	using AddNode<uT>::AddNode;
};

template<class uNode> struct Maximum : Add<uNode>
{
	using Node = uNode;
	using T = typename Node::T;

	Node identity{std::numeric_limits<T>::min()};

	Node merge(const Node& lhs, const Node& rhs) { return std::max(lhs.value, rhs.value); }

	void propagate_update(Node& parent, Node& leftChild, Node& rightChild, const std::size_t& treeLeft, const std::size_t& treeRight, const std::size_t& queryLeft, const std::size_t& queryRight, const std::size_t& treeSize)
	{
		std::size_t intervalLength{treeRight - treeLeft + 1};
		if(parent.validSet)
		{
			if(intervalLength > 1)
			{
				leftChild.set = rightChild.set = parent.set;
				leftChild.validSet = rightChild.validSet = true;
				leftChild.delta = rightChild.delta = 0;
			}
			parent.value = parent.set;
			parent.validSet = false;
		}
		if(parent.delta)
		{
			if(intervalLength > 1)
			{
				leftChild.delta += parent.delta;
				rightChild.delta += parent.delta;
			}
			parent.value += parent.delta;
			parent.delta = 0;
		}
	}
};

#endif