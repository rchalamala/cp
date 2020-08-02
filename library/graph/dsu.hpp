#ifndef DSU_HPP
#define DSU_HPP

// Verification:
// https://judge.yosupo.jp/submission/17527/

#include <cstddef>
#include <numeric>
#include <vector>

class DSU
{
	std::vector<std::size_t> m_parent, m_sizes;
public:

	explicit DSU(const std::size_t& size)
	{
		m_parent.resize(size);
		std::iota(m_parent.begin(), m_parent.end(), 0);
		m_sizes.assign(size, 1);
	}

	std::size_t root(std::size_t i)
	{
		while (i != m_parent[i]) i = m_parent[i] = m_parent[m_parent[i]];
		return i;
	}

	bool connect(std::size_t i, std::size_t j)
	{
		if ((i = root(i)) == (j = root(j))) return false;
		if (m_sizes[i] >= m_sizes[j])
		{
			m_sizes[i] += m_sizes[j];
			m_parent[j] = i;
		}
		else
		{
			m_sizes[j] += m_sizes[i];
			m_parent[i] = j;
		}
		return true;
	}
};

#endif