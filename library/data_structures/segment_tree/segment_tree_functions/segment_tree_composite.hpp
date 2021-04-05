#ifndef SEGMENT_TREE_COMPOSITE
#define SEGMENT_TREE_COMPOSITE

#include <cstddef>

template<typename T1, typename T2> T1 power(T1 base, T2 exponent)
{
	T1 result{1};
	while(exponent)
	{
		if(exponent & 1)
		{ result *= base; }
		base *= base;
		exponent >>= 1;
	}
	return result;
}

template<typename uT> struct CompositeNode
{
	using T = uT;

	T a{1}, b{};
	bool validSet{};

	CompositeNode(const T& uA, const T& uB) : a{uA}, b{uB}
	{
	}

	CompositeNode()
	{
	}
};

template<class uNode, bool ORDERED> struct Composite
{
	using Node = uNode;
	using T = typename Node::T;

	Node identity{};

	Node return_value(const Node& element)
	{
		return element;
	}

	Node merge(const Node& lhs, const Node& rhs)
	{
		return ORDERED ? Node{lhs.a * rhs.a, lhs.a * rhs.b + lhs.b} : Node{rhs.a * lhs.a, rhs.a * lhs.b + rhs.b};
	}

	void propagate_update(Node& parent, Node& leftChild, Node& rightChild, const std::size_t& treeLeft, const std::size_t& treeRight, const std::size_t& queryLeft, const std::size_t& queryRight, const std::size_t& treeSize)
	{
		std::size_t intervalLength{treeRight - treeLeft + 1};
		if(parent.validSet)
		{
			if(intervalLength > 1)
			{
				leftChild.a = rightChild.a = parent.a;
				leftChild.b = rightChild.b = parent.b;
				leftChild.validSet = rightChild.validSet = true;
			}
			T a = parent.a;
			if(parent.a > 1)
			{
				parent.a = power(a, intervalLength);
				parent.b *= (parent.a - 1);
				parent.b /= (a - 1);
			}
			else if(parent.a == 1)
			{ parent.b *= intervalLength; }
			parent.validSet = false;
		}
	}

	void change(Node& element, const std::size_t& treeLeft, const std::size_t& treeRight, const std::size_t& queryLeft, const std::size_t& queryRight, const std::size_t& treeSize, const T& a, const T& b)
	{
		element.a = a;
		element.b = b;
		element.validSet = true;
	}
};

#endif