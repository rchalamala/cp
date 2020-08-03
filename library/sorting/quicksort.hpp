#ifndef QUICKSORT_HPP
#define QUICKSORT_HPP

// Verification:
//

#include <cstddef>
#include <stack>
#include <utility>
#include <vector>

template<typename T> std::size_t partition(std::vector<T>& elements, const std::size_t& left, const std::size_t& right)
{
	std::size_t i;
	T pivot = elements[left];
	for(std::size_t j = (i = left + 1); j <= right; j++)
		if(elements[j] < pivot)
			std::swap(elements[i++], elements[j]);
	std::swap(elements[left], elements[--i]);
	return i;
}

template<typename T> void sort(std::vector<T>& elements)
{
	std::stack<std::pair<std::size_t, std::size_t>> recursion;
	recursion.emplace(0, elements.size() - 1);
	while(!recursion.empty())
	{
		auto part = recursion.top();
		recursion.pop();
		std::size_t pivot = partition(elements, part.first, part.second);
		if(pivot > 0 && pivot - 1 > part.first) recursion.emplace(part.first, pivot - 1);
		if(pivot + 1 < part.second) recursion.emplace(pivot + 1, part.second);
	}
}

#endif