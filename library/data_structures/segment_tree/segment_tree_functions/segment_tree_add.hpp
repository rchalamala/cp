#ifndef SEGMENT_TREE_ADD_HPP
#define SEGMENT_TREE_ADD_HPP

#include <cstddef>
#include <type_traits>

#include "../../../general/unused.hpp"

template<typename T> struct AddNode
{
	static_assert(std::is_integral_v<T>);

	T m_value = 0, m_delta = 0, m_set = 0;
	bool m_validSet = false;

	AddNode(const T& value, const T& delta, const T& set, const bool& validSet) : m_value{value}, m_delta{delta}, m_set{set}, m_validSet{validSet}
	{
	}

	AddNode(const T& value) : m_value{value}, m_delta{}, m_set{}, m_validSet{}
	{
	}

	AddNode() : m_value{}, m_delta{}, m_set{}, m_validSet{}
	{
	}
};

template<typename T, typename Node> struct Add
{
	static_assert(std::is_integral_v<T>);

	Node identity = Node{};

	T return_value(const Node& element)
	{
		return element.m_value;
	}

	T value(const Node& lhs, const Node& rhs)
	{
		return lhs.m_value + rhs.m_value;
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
			parent.m_value = intervalLength * parent.m_set;
			parent.m_validSet = false;
		}
		else if(parent.m_delta)
		{
			if(intervalLength > 1)
			{
				leftChild.m_delta += parent.m_delta;
				rightChild.m_delta += parent.m_delta;
			}
			parent.m_value += intervalLength * parent.m_delta;
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