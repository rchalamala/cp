#ifndef SEGMENT_TREE_AFFINE_HPP
#define SEGMENT_TREE_AFFINE_HPP

#include <cstddef>


template<typename uT> struct AffineNode
{
	using T = uT;

	T value{}, b{1}, c{};

	AffineNode(const T& uValue, const T& uB, const T& uC) : value{uValue}, b{uB}, c{uC} {}

	AffineNode(const T& uValue) : value{uValue} {}

	AffineNode() {}
};


template<class uNode> struct Affine
{
	using Node = uNode;
	using T = typename Node::T;

	Node identity{};

	T return_value(const Node& element) { return element.value; }

	Node merge(const Node& lhs, const Node& rhs) { return lhs.value + rhs.value; }

	void propagate_update(Node& parent, Node& leftChild, Node& rightChild, const std::size_t& treeLeft, const std::size_t& treeRight, const std::size_t& queryLeft, const std::size_t& queryRight, const std::size_t& treeSize)
	{
		std::size_t intervalLength{treeRight - treeLeft + 1};
		if(parent.b)
		{
			if(intervalLength > 1)
			{
				leftChild.b *= parent.b;
				(leftChild.c *= parent.b) += parent.c;
				rightChild.b *= parent.b;
				(rightChild.c *= parent.b) += parent.c;
			}
			((parent.value *= parent.b) += (parent.c * intervalLength));
			parent.b = 1;
			parent.c = 0;
		}
	}

	void change(Node& element, const std::size_t& treeLeft, const std::size_t& treeRight, const std::size_t& queryLeft, const std::size_t& queryRight, const std::size_t& treeSize, const T& b, const T& c)
	{
		element.b *= b;
		(element.c *= b) += c;
	}
};

#endif