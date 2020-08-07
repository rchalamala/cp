#ifndef GRAPH_HPP
#define GRAPH_HPP

// Verification:
//

#include <algorithm>
#include <array>
#include <cstddef>
#include <iterator>
#include <vector>

template<class Edge> class Graph
{
	std::vector<std::vector<Edge>> graph;
public:
	Graph(const std::size_t& N) : graph{N, std::vector<Edge>()} {}

	template<typename...Args> void addEdge(const std::size_t& from, const std::size_t& to, Args& ... args)
	{
		graph[from].emplace_back(to, args...);
		if(Edge::reversable) graph[to].emplace_back(from, args...);
	}

	void extend() { graph.emplace_back(); }

	std::size_t size() const noexcept { return graph.size(); }

	bool empty() const noexcept { return graph.empty(); }

	template<typename InputIterator> void assign(InputIterator first, InputIterator last) { graph.assign(first, last); }

	void assign(const std::size_t& N, const std::vector<Edge>& value) { graph.assign(N, value); }

	void assign(const std::initializer_list<std::vector<Edge>>& elements) { graph.assign(elements); }

	auto begin() noexcept { return graph.begin(); }

	auto begin() const noexcept { return graph.begin(); }

	auto end() noexcept { return graph.end(); }

	auto end() const noexcept { return graph.end(); }

	auto rbegin() noexcept { return graph.rbegin(); }

	auto rbegin() const noexcept { return graph.rbegin(); }

	auto rend() noexcept { return graph.rend(); }

	auto rend() const noexcept { return graph.rend(); }

	auto cbegin() const noexcept { return graph.cbegin(); }

	auto cend() const noexcept { return graph.cend(); }

	auto crbegin() const noexcept { return graph.crbegin(); }

	auto crend() const noexcept { return graph.crend(); }

	auto& operator[](const std::size_t& at) { return graph[at]; }

	const auto& operator[](const std::size_t& at) const { return graph[at]; }

	auto& at(const std::size_t& at) { return graph.at(at); };

	const auto& at(const std::size_t& at) const { return graph.at(at); };

	auto& front() { return graph.front(); }

	const auto& front() const { return graph.front(); }

	auto& back() { return graph.back(); }

	const auto& back() const { return graph.back(); }

	void clear() noexcept { graph.clear(); }

	void resize(const std::size_t& N) { graph.resize(N); };

	void resize(const std::size_t& N, const std::vector<Edge>& value) { graph.resize(N, value); };
};

#endif