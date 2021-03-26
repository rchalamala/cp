// Verification:
//

#include "bubble_sort.h"

#include <algorithm>
#include <iterator>
#include <utility>

template <typename Iterator,
          typename Comparator =
              std::less<typename std::iterator_traits<Iterator>::value_type>>
void bubble_sort(Iterator first, Iterator last,
                 Comparator compare) {
  for (Iterator i = first; i != last; ++i)
    for (Iterator j = first; j != i; ++j)
      if (compare(*i, *j)) std::iter_swap(i, j);
}