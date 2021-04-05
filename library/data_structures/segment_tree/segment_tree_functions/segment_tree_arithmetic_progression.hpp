#ifndef SEGMENT_TREE_ARITHMETIC_PROGRESSION_HPP
#define SEGMENT_TREE_ARITHMETIC_PROGRESSION_HPP

#include <cstddef>
#include <type_traits>
#include "segment_tree_add.hpp

template<typename uT, std::enable_if_t<std::is_arithmetic_v<uT>, bool> = true> struct ArithmeticProgressionNode
{
	using T = uT;

	T value{}, delta{}, deltaAP{};

	ArithmeticProgressionNode(const T& uValue, const T& uDelta, const T& uDeltaAP) : value{uValue}, delta{uDelta}, deltaAP{uDeltaAP}
	{
	}

	ArithmeticProgressionNode(const T& uValue) : value{uValue}
	{
	}

	ArithmeticProgressionNode()
	{
	}
};

template<class uNode> struct ArithmeticProgression
{
	using Node = uNode;
	using T = typename Node::T;

	Node identity{};

	T return_value(const Node& element)
	{
		return element.value;
	}

	Node merge(const Node& lhs, const Node& rhs)
	{
		return lhs.value + rhs.value;
	}

	void propagate_update(Node& parent, Node& leftChild, Node& rightChild, const std::size_t& treeLeft, const std::size_t& treeRight, const std::size_t& queryLeft, const std::size_t& queryRight, const std::size_t& treeSize)
	{
		std::size_t intervalLength{treeRight - treeLeft + 1};
		if(parent.delta)
		{
			if(intervalLength > 1)
			{
				leftChild.delta += parent.delta;
				rightChild.delta += parent.delta;
			}
			parent.value += intervalLength * parent.delta;
			parent.delta = 0;
		}
		if(parent.deltaAP)
		{
			if(intervalLength > 1)
			{
				leftChild.deltaAP += parent.deltaAP;
				rightChild.deltaAP += parent.deltaAP;
				rightChild.delta += parent.deltaAP * ((intervalLength + 1) >> 1);
			}
			parent.value += ((intervalLength * (intervalLength + 1)) >> 1) * parent.deltaAP;
			parent.deltaAP = 0;
		}
	}

	void change(Node& element, const std::size_t& treeLeft, const std::size_t& treeRight, const std::size_t& queryLeft, const std::size_t& queryRight, const std::size_t& treeSize, const T& value)
	{
		element.delta += value;
	}

	void change(Node& element, const std::size_t& treeLeft, const std::size_t& treeRight, const std::size_t& queryLeft, const std::size_t& queryRight, const std::size_t& treeSize, const T& k, const bool& isAP)
	{
		element.delta += (treeLeft - queryLeft) * k;
		element.deltaAP += k;
	}

	void change(Node& element, const std::size_t& treeLeft, const std::size_t& treeRight, const std::size_t& queryLeft, const std::size_t& queryRight, const std::size_t& treeSize, const T& value, const T& k)
	{
		element.delta += value + (treeLeft - queryLeft) * k;
		element.deltaAP += k;
	}
};

#endif