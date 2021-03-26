#ifndef DSU_HPP
#define DSU_HPP

// https://codeforces.com/blog/entry/82400
// Verification:
//

#include <algorithm>
#include <cstddef>
#include <type_traits>
#include <vector>

template <class T>
class DSU {
  std::vector<T> m_parent_or_sizes;
  std::size_t m_component_count;

 public:
  explicit DSU(const std::size_t& size)
      : m_parent_or_sizes(size, -1), m_component_count{size} {
    static_assert(std::is_integral<T>::value);
    static_assert(std::is_signed<T>::value);
  }

  T root(const std::size_t& i) {
    assert(0 <= i && i < m_parent_or_sizes.size());
    if (m_parent_or_sizes[i] < 0) return i;
    return m_parent_or_sizes[i] = root(m_parent_or_sizes[i]);
  }

  T connect(std::size_t i, std::size_t j) {
    assert(0 <= i && i < m_parent_or_sizes.size());
    assert(0 <= j && j < m_parent_or_sizes.size());
    if ((i = root(i)) == (j = root(j))) return false;
    if (-m_parent_or_sizes[i] < -m_parent_or_sizes[j]) {
      m_parent_or_sizes[i] += m_parent_or_sizes[j];
      m_parent_or_sizes[j] = i;
    } else {
      m_parent_or_sizes[j] += m_parent_or_sizes[i];
      m_parent_or_sizes[i] = j;
    }
    return --m_component_count;
  }

  T size(const std::size_t& i) {
    assert(0 <= i && i < m_parent_or_sizes.size());
    return -m_parent_or_sizes[root(i)];
  }

  bool connected(const std::size_t& i, const std::size_t& j) {
    assert(0 <= i && i < m_parent_or_sizes.size());
    assert(0 <= j && j < m_parent_or_sizes.size());
    return root(i) == root(j);
  }

  std::vector<std::vector<std::size_t>> generate_components() {
    std::vector<std::size_t> head(m_parent_or_sizes.size(), 0),
        sizes(m_parent_or_sizes.size(), 0);
    for (std::size_t i = 0; i < m_parent_or_sizes.size();
         ++sizes[(head[i] = root(i))], ++i)
      ;
    std::vector<std::vector<std::size_t>> result(m_parent_or_sizes.size());
    for (std::size_t i = 0; i < m_parent_or_sizes.size();
         result[i].reserve(sizes[i]), ++i)
      ;
    for (std::size_t i = 0; i < m_parent_or_sizes.size();
         result[head[i]].push_back(i), ++i)
      ;
    result.erase(std::remove_if(result.begin(), result.end(),
                                [](const std::vector<T>& component) -> bool {
                                  return component.empty();
                                }),
                 result.end());
    return result;
  }

  [[nodiscard]] std::size_t component_count() const {
    return m_component_count;
  }
};

#endif