#ifndef SEGMENT_TREE_MINIMUM_HPP
#define SEGMENT_TREE_MINIMUM_HPP

#include <algorithm>

template<typename T> struct MinimumNode
{
	T m_value, m_delta, m_set;
	bool m_validSet;

	MinimumNode(const T& value, const T& delta, const T& set, const bool& validSet) : m_value{value}, m_delta{delta}, m_set{set}, m_validSet{validSet} {}

	MinimumNode(const T& value) : m_value{value}, m_delta{}, m_set{}, m_validSet{} {}

	MinimumNode() : m_value{}, m_delta{}, m_set{}, m_validSet{} {}
};

template<typename T, typename Node> struct Minimum
{
	Node identity = Node{std::numeric_limits<T>::max()};

	T return_value(const Node& element)
	{
		return element.m_value;
	}

	T value(const Node& lhs, const Node& rhs)
	{
		return std::min(lhs.m_value, rhs.m_value);
	}

	void propagate_update(Node& parent, Node& leftChild, Node& rightChild, const std::size_t& treeLeft, const std::size_t& treeRight, const std::size_t& treeSize)
	{
		unused(treeSize);
		std::size_t intervalLength = treeRight - treeLeft + 1;
		if(parent.m_validSet)
		{
			if(intervalLength > 1)
			{
				leftChild.m_set = rightChild.m_set = parent.m_set;
				leftChild.m_delta = rightChild.m_delta = 0;
			}
			parent.m_value = parent.m_set;
			parent.m_validSet = false;
		}
		else if(parent.m_delta)
		{
			if(intervalLength > 1)
			{
				leftChild.m_delta += parent.m_delta;
				rightChild.m_delta += parent.m_delta;
			}
			parent.m_value += parent.m_delta;
			parent.m_delta = 0;
		}
	}

	void change(Node& element, const T& delta)
	{
		element.m_value += delta;
	}

	void change(Node& element, const T& set, const bool& notDelta)
	{
		unused(notDelta);
		element.m_delta = 0;
		element.m_set = set;
		element.m_validSet = true;
	}
};

#endif