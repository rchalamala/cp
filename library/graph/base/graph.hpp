#ifndef GRAPH_HPP
#define GRAPH_HPP

// Verification:
//

#include <algorithm>
#include <array>
#include <cstddef>
#include <vector>

template<class Edge> class Graph
{
	std::vector<std::vector<Edge>> graph;
public:
	Graph() = default;

	Graph(const std::size_t& N) : graph{N, std::vector<Edge>()} {}

	void initialize(const std::size_t& N) { graph = std::vector<std::vector<Edge>>(N, std::vector<Edge>()); }

	template<typename...Args> void addEdge(const std::size_t& from, const std::size_t& to, Args& ... args)
	{
		graph[from].emplace_back(to, args...);
		if(Edge::reversable) graph[to].emplace_back(from, args...);
	}

	void assign(const std::size_t& N, const std::vector<Edge>& value) { graph.assign(N, value); }

	template<typename T> void assign(T first, T last) { graph.assign(first, last); }

	void assign(std::initializer_list<std::vector<Edge>> elements) { graph.assign(elements); }

	void resize(const std::size_t& N) { graph.resize(N); }

	void resize(const std::size_t& N, const std::vector<Edge>& value) { graph.resize(N, value); }

	bool empty() const noexcept { return graph.empty(); }

	std::size_t size() const noexcept { return graph.size(); }

	void clear() noexcept { graph.clear(); }

	auto begin() noexcept { return graph.begin(); }

	auto cbegin() const noexcept { return graph.begin(); }

	auto end() noexcept { return graph.end(); }

	auto cend() const noexcept { return graph.end(); }

	auto rbegin() noexcept { return graph.rbegin(); }

	auto crbegin() const noexcept { return graph.rbegin(); }

	auto rend() noexcept { return graph.rend(); }

	auto crend() const noexcept { return graph.rend(); }

	std::vector<Edge>& operator[](const std::size_t& index) { return graph[index]; }

	std::vector<Edge>& operator[](const std::size_t& index) const { return graph[index]; }

	auto front() { return graph.front(); }

	auto front() const { return graph.front(); }

	auto back() { return graph.back(); }

	auto back() const { return graph.back(); }
};

#endif