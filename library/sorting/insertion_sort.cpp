// Verification:
//

#include "insertion_sort.h"

#include <algorithm>
#include <iterator>

template <typename Iterator,
          typename Comparator =
              std::less<typename std::iterator_traits<Iterator>::value_type>>
void insertion_sort(Iterator first, Iterator last,
                    Comparator compare) {
  for (Iterator i = first; i != last; ++i) {
    auto key = *i;
    Iterator j = i;
    while (j != first && compare(key, *std::prev(j))) {
      std::iter_swap(j, std::prev(j));
      j = std::prev(j);
    }
    *j = key;
  }
}