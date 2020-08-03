#ifndef BUBBLESORT_HPP
#define BUBBLESORT_HPP

// Verification:
//

#include <cstddef>
#include <utility>
#include <vector>

template<typename T> void sort(std::vector<T>& elements)
{
	for(std::size_t i = 0; i < elements.size() - 1; ++i)
		for(std::size_t j = 0; j < elements.size() - i - 1; ++j)
			if(elements[j] > elements[j + 1])
				std::swap(elements[j], elements[j + 1]);
}

#endif
