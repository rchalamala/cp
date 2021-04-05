#ifndef SEGMENT_TREE_ADD_HPP
#define SEGMENT_TREE_ADD_HPP

#include <cstddef>
#include <type_traits>

template<typename uT, std::enable_if_t<std::is_arithmetic_v<uT>, bool> = true> struct AddNode
{
	using T = uT;

	T value{}, delta{}, set{};
	bool validSet{};

	AddNode(const T& uValue) : value{uValue}
	{
	}

	AddNode()
	{
	}
};

template<class uNode> struct Add
{
	using Node = uNode;
	using T = typename Node::T;

	Node identity{};

	virtual T return_value(const Node& element)
	{
		return element.value;
	}

	virtual Node merge(const Node& lhs, const Node& rhs)
	{
		return lhs.value + rhs.value;
	}

	virtual void propagate_update(Node& parent, Node& leftChild, Node& rightChild, const std::size_t& treeLeft, const std::size_t& treeRight, const std::size_t& queryLeft, const std::size_t& queryRight, const std::size_t& treeSize)
	{
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
	}

	virtual void change(Node& element, const std::size_t& treeLeft, const std::size_t& treeRight, const std::size_t& queryLeft, const std::size_t& queryRight, const std::size_t& treeSize, const T& delta)
	{
		element.delta += delta;
	}

	virtual void change(Node& element, const std::size_t& treeLeft, const std::size_t& treeRight, const std::size_t& queryLeft, const std::size_t& queryRight, const std::size_t& treeSize, const T& set, const bool& notDelta)
	{
		element.delta = 0;
		element.set = set;
		element.validSet = true;
	}
};

#endif