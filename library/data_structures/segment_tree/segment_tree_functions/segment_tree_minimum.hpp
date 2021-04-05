#ifndef SEGMENT_TREE_MINIMUM_HPP
#define SEGMENT_TREE_MINIMUM_HPP

#include <algorithm>
#include <cstddef>
#include <type_traits>

#include "../../../general/unused.hpp"

template<typename uT, std::enable_if_t<std::is_arithmetic_v<uT>, bool> = true> struct MinimumNode
{
	using T = uT;

	T value{}, delta{}, set{};
	bool validSet{};

	MinimumNode(const T& uValue, const T& uDelta, const T& uSet, const bool& uValidSet) : value{uValue}, delta{uDelta}, set{uSet}, validSet{uValidSet}
	{
	}

	MinimumNode(const T& uValue) : value{uValue}
	{
	}
};

template<class uNode> struct Minimum
{
	using Node = uNode;
	using T = typename Node::T;

	Node identity{};

	T return_value(const Node& element)
	{
		return element.value;
	}

	T value(const Node& lhs, const Node& rhs)
	{
		return std::max(lhs.value, rhs.value);
	}

	void propagate_update(Node& parent, Node& leftChild, Node& rightChild, const std::size_t& treeLeft, const std::size_t& treeRight, const std::size_t& treeSize)
	{
		unused(treeSize);
		std::size_t intervalLength{treeRight - treeLeft + 1};
		if(parent.validSet)
		{
			if(intervalLength > 1)
			{
				leftChild.set = rightChild.set = parent.set;
				leftChild.delta = rightChild.delta = 0;
			}
			parent.value = intervalLength * parent.set;
			parent.validSet = false;
		}
		else if(parent.delta)
		{
			if(intervalLength > 1)
			{
				leftChild.delta += parent.delta;
				rightChild.delta += parent.delta;
			}
			parent.value += intervalLength * parent.delta;
			parent.delta = 0;
		}
	}

	void change(Node& element, const T& delta)
	{
		element.value += delta;
	}

	void change(Node& element, const T& set, const bool& notDelta)
	{
		unused(notDelta);
		element.delta = 0;
		element.set = set;
		element.validSet = true;
	}
};

#endif