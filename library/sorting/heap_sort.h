#ifndef HEAP_SORT_H
#define HEAP_SORT_H

#include <algorithm>
#include <iterator>

template <typename Iterator, typename Comparator>
void heap_sort(Iterator first, Iterator last, Comparator compare);

#endif
