#ifndef COUNTINGSORT_HPP
#define COUNTINGSORT_HPP

// Verification:
//

#include <algorithm>
#include <cstddef>
#include <vector>

template<typename T> void sort(std::vector<T>& elements)
{
	const auto minmax = std::minmax_element(elements.begin(), elements.end());
	const T minimum = *minmax.first, maximum = *minmax.second;
	std::vector<std::size_t> auxilary(maximum - minimum + 1, 0);
	for(const auto& element : elements) ++auxilary[element - minimum];
	std::size_t index = 0;
	for(std::size_t value = 0; value <= maximum - minimum; ++value)
		while(auxilary[value]--)
			elements[index++] = value + minimum;
}

#endif