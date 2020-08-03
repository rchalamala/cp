#ifndef BIT_HPP
#define BIT_HPP

// Verification:
//

#include <cstddef>
#include <vector>

template<class T> class BIT
{
	std::vector<T> m_tree;
public:
	explicit BIT(const std::size_t& size) { m_tree.assign(size + 1, 0); }

	void update(std::size_t i, const T& delta) { for(++i; i < m_tree.size(); i += (i & (-i))) m_tree[i] += delta; }

	T query(std::size_t i)
	{
		T sum = 0;
		for(++i; i; i -= (i & (-i))) sum += m_tree[i];
		return sum;
	}

	T query(const std::size_t& i, const std::size_t& j) { return query(j) - (i ? query(i - 1) : 0); }
};

#endif