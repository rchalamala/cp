#ifndef SELECTION_SORT_HPP
#define SELECTION_SORT_HPP

// Verification:
//

#include <algorithm>
#include <iterator>

template<typename Iterator, typename Comparator = std::less<typename std::iterator_traits<Iterator>::value_type>> void selection_sort(Iterator first, Iterator last, Comparator compare = Comparator()) { for(Iterator i = first; i != last; ++i) std::iter_swap(i, std::min_element(i, last, compare)); }

#endif