#ifndef SELECTIONSORT_HPP
#define SELECTIONSORT_HPP

#include <cstddef>
#include <utility>
#include <vector>

template<typename T>
void sort(std::vector<T>& elements)
{
	for (std::size_t i = 0; i < elements.size() - 1; ++i)
	{
		std::size_t minimum = i;
		for (std::size_t j = i + 1; j < elements.size(); ++j)
			if (elements[j] < elements[minimum])
				minimum = j;
		std::swap(elements[i], elements[minimum]);
	}
}

#endif