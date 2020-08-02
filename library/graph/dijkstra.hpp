#ifndef DIJKSTRA_HPP
#define DIJKSTRA_HPP

// Verification:
// https://codeforces.com/contest/20/submission/88716972/

#include "base/graph.hpp"
#include <cstddef>
#include <queue>
#include <vector>

template<class T, class Edge>
class Dijkstra
{
	Graph<Edge> m_graph;
	std::vector<T> m_costs;
	std::vector<std::size_t> m_parents;
	std::vector<bool> m_visited;
	std::priority_queue<std::pair<T, std::size_t>,
						std::vector<std::pair<T, std::size_t>>,
						std::greater<std::pair<T, std::size_t>>> m_next;
public:
	explicit Dijkstra(const Graph<Edge>& graph)
			:m_graph{ graph }
	{
		reset();
	}

	void explore(const std::size_t& source, const bool& clear = false)
	{
		if (clear) reset();
		m_costs[source] = 0;
		m_parents[source] = source;
		m_next.emplace(m_costs[source], source);
		while (!m_next.empty())
		{
			std::size_t top = m_next.top().second;
			m_next.pop();
			if (m_visited[top]) continue;
			m_visited[top] = true;
			for (const auto& neighbor : m_graph[top])
				if (!m_visited[neighbor.to] && m_costs[neighbor.to] > m_costs[top] + neighbor.weight)
				{
					m_costs[neighbor.to] = m_costs[top] + neighbor.weight;
					m_parents[neighbor.to] = top;
					m_next.emplace(m_costs[neighbor.to], neighbor.to);
				}
		}
	}

	void reset()
	{
		m_costs.assign(m_graph.size(), std::numeric_limits<T>::max());
		m_parents.assign(m_graph.size(), std::numeric_limits<T>::max());
		m_visited.assign(m_graph.size(), false);
	}

	std::vector<T> costs() const
	{
		return m_costs;
	}

	std::vector<std::size_t> parents() const
	{
		return m_parents;
	}

	std::vector<bool> visited() const
	{
		return m_visited;
	}
};

#endif