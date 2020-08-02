#ifndef KOSARAJUS_SCCS_HPP
#define KOSARAJUS_SCCS_HPP

// Verification:
// https://judge.yosupo.jp/submission/17531/

#include "base/graph.hpp"
#include "base/edges/edge.hpp"
#include <cstddef>
#include <stack>
#include <vector>

class KosarajusSCCs
{
	Graph<Edge> m_transposed;
	std::vector<std::vector<std::size_t>> m_SCCs;
	std::vector<bool> m_visited;
	std::stack<std::size_t> m_order;

	void dfs(Graph<Edge>& graph, const std::size_t& i)
	{
		m_visited[i] = true;
		for (const auto& neighbor : graph[i])
			if (!m_visited[neighbor.to])
				dfs(graph, neighbor.to);
		m_order.push(i);
	}

	void transposedDFS(const std::size_t& i, const std::size_t& index)
	{
		m_SCCs[index].push_back(i);
		m_visited[i] = false;
		for (const auto& neighbor : m_transposed[i])
			if (m_visited[neighbor.to])
				transposedDFS(neighbor.to, index);
	}

public:
	explicit KosarajusSCCs(Graph<Edge>& graph)
	{
		m_transposed.initialize(graph.size());
		m_visited.assign(graph.size(), false);
		for (std::size_t i = 0; i < graph.size(); ++i)
		{
			if (!m_visited[i]) dfs(graph, i);
			for (const auto& neighbor : graph[i])
				m_transposed.addEdge(neighbor.to, i);
		}
		while (!m_order.empty())
		{
			std::size_t i = m_order.top();
			m_order.pop();
			if (m_visited[i])
			{
				m_SCCs.emplace_back();
				transposedDFS(i, m_SCCs.size() - 1);
			}
		}
	}

	std::vector<std::vector<std::size_t>> SCCs()
	{
		return m_SCCs;
	}
};

#endif