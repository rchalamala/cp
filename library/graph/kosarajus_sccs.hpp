#ifndef KOSARAJUS_SCCS_HPP
#define KOSARAJUS_SCCS_HPP

// Verification:
//

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

public:
	explicit KosarajusSCCs(Graph<Edge>& graph)
	{
		m_transposed.initialize(graph.size());
		m_visited.assign(graph.size(), false);
		for(std::size_t i = 0; i < graph.size(); ++i)
		{
			if(!m_visited[i])
			{
				std::stack<std::size_t> recursion;
				recursion.push(i);
				while(!recursion.empty())
				{
					std::size_t at = recursion.top();
					recursion.pop();
					m_visited[at] = true;
					for(const auto& neighbor : m_transposed[at])
						if(!m_visited[neighbor.to])
							recursion.push(neighbor.to);
				}
			}
			for(const auto& neighbor : graph[i]) m_transposed.addEdge(neighbor.to, i);
		}
		while(!m_order.empty())
		{
			std::size_t i = m_order.top();
			m_order.pop();
			if(m_visited[i])
			{
				m_SCCs.emplace_back();
				std::stack<std::size_t> recursion;
				recursion.push(i);
				while(!recursion.empty())
				{
					std::size_t at = recursion.top();
					recursion.pop();
					m_SCCs.back().push_back(at);
					m_visited[at] = false;
					for(const auto& neighbor : m_transposed[at])
						if(m_visited[neighbor.to])
							recursion.push(neighbor.to);
				}
			}
		}
	}

	std::vector<std::vector<std::size_t>> SCCs() { return m_SCCs; }
};

#endif