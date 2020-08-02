#ifndef GRAPH_HPP
#define GRAPH_HPP

#include <algorithm>
#include <array>
#include <cstddef>
#include <vector>

template<class Edge>
struct Graph
{
	std::size_t m_N;
	std::vector<std::vector<Edge>> graph;
public:
	Graph() = default;

	Graph(const std::size_t& N)
			:m_N{ N }, graph{ N, std::vector<Edge>() }
	{
	}

	void initialize(const std::size_t& N)
	{
		m_N = N;
		graph = std::vector<std::vector<Edge>>(N, std::vector<Edge>());
	}

	template<typename...Args>
	void addEdge(const std::size_t& from, const std::size_t& to, Args& ... args)
	{
		graph[from].emplace_back(to, args...);
		if (Edge::reversable) graph[to].emplace_back(from, args...);
	}

	std::vector<Edge>& operator[](const std::size_t& index)
	{
		return graph[index];
	}

	void extend(const std::size_t& N)
	{
		graph.resize(m_N += N);
	}

	void clear()
	{
		graph.assign(m_N, std::vector<Edge>());
	}

	std::size_t size() const
	{
		return m_N;
	}
};

#endif