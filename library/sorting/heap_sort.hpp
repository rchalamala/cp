#ifndef HEAP_SORT_HPP
#define HEAP_SORT_HPP

// Verification:
//

#include <algorithm>
#include <iterator>

template<typename Iterator, typename Comparator = std::less<typename std::iterator_traits<Iterator>::value_type>> void heap_sort(Iterator first, Iterator last, Comparator compare = Comparator())
{
	std::make_heap(first, last, compare);
	std::sort_heap(first, last, compare);
}

#endif