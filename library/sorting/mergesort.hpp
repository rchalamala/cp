#ifndef MERGESORT_HPP
#define MERGESORT_HPP

// Verification:
//

#include <cstddef>
#include <vector>

template<typename T> void merge(std::vector<T>& elements, std::vector<T>& temporary, const std::size_t& left, const std::size_t& midpoint, const std::size_t& right)
{
	std::size_t i = left, j = midpoint + 1, k = left;
	while(i <= midpoint && j <= right) temporary[k++] = (elements[i] <= elements[j] ? elements[i++] : elements[j++]);
	while(i < elements.size() && i <= midpoint) temporary[k++] = elements[i++];
	while(j < elements.size() && j <= right) temporary[k++] = elements[j++];
	for(std::size_t index = left; index <= right; ++index) elements[index] = temporary[index];
}

template<typename T> void sort(std::vector<T>& elements)
{
	std::vector<T> temporary(elements.size());
	for(std::size_t midpoint = 1; midpoint < elements.size(); midpoint *= 2)
		for(std::size_t left = 0; left < elements.size(); left += midpoint * 2)
			merge(elements, temporary, left, left + midpoint - 1, std::min(left + midpoint * 2 - 1, elements.size() - 1));
}

#endif