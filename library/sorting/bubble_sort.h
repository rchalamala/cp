#ifndef BUBBLE_SORT_H
#define BUBBLE_SORT_H

#include <algorithm>
#include <iterator>
#include <utility>

template <typename Iterator, typename Comparator>
void bubble_sort(Iterator first, Iterator last, Comparator compare);

#endif
