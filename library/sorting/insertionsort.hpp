#ifndef INSERTIONSORT_HPP
#define INSERTIONSORT_HPP

#include <cstddef>
#include <utility>
#include <vector>

template<typename T>
void sort(std::vector<T>& elements)
{
	for (std::size_t i = 0; i < elements.size(); ++i)
	{
		T key = elements[i];
		std::size_t j = i;
		while (j && key < elements[j - 1])
		{
			std::swap(elements[j], elements[j - 1]);
			--j;
		}
		elements[j] = key;
	}
}

#endif
