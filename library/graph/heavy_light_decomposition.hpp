#ifndef HEAVY_LIGHT_DECOMPOSITION_HPP
#define HEAVY_LIGHT_DECOMPOSITION_HPP

#include <cstddef>
#include <type_traits>
#include <utility>
#include <array>

template<class Tree> class HeavyLightDecomposition
{
	std::vector <std::size_t> sizes, parent, depths, head;
	std::vector <std::pair<std::size_t, std::size_t>> times;
	Tree tree;

	void dfs(std::vector <std::vector<std::size_t>>& graph, const std::size_t& i)
	{
		sizes[i] = 1;
		for(auto& child : graph[i])
		{
			if(child != parent[i])
			{
				parent[child] = i;
				depths[child] = depths[i] + 1;
				dfs(graph, child);
				sizes[i] += sizes[child];
				if(graph[i][0] == parent[i] || sizes[child] > sizes[graph[i][0]])
				{ std::swap(graph[i][0], child); }
			}
		}
	}

	std::size_t currentTime = 0;

	void decompose(std::vector <std::vector<std::size_t>>& graph, const std::size_t& i)
	{
		times[i].first = currentTime++;
		for(const auto& child : graph[i])
		{
			if(child != parent[i])
			{
				head[child] = (graph[i][0] == child ? head[i] : child);
				decompose(graph, child);
			}
		}
		times[i].second = currentTime - 1;
	}

	template<typename F> void path(std::size_t u, std::size_t v, const F f)
	{
		for(; head[u] != head[v]; v = parent[head[v]])
		{
			if(depths[head[u]] > depths[head[v]])
			{ std::swap(u, v); }
			f(times[head[v]].first, times[v].first);
		}
		if(depths[u] > depths[v])
		{ std::swap(u, v); }
		f(times[u].first, times[v].first);
	}

public:
	explicit HeavyLightDecomposition(std::vector <std::vector<std::size_t>>& graph, const std::size_t& root = 0) : sizes(graph.size()), parent(graph.size()), depths(graph.size()), head(graph.size()), times(graph.size()), tree{graph.size()}
	{
		parent[root] = root;
		depths[root] = 0;
		dfs(graph, root);
		head[root] = root;
		decompose(graph, root);
	}

	template<typename Iterable> void build(const Iterable& elements)
	{
		Iterable positionedElements(elements.size());
		for(std::size_t i = 0; i < positionedElements.size(); ++i)
		{ positionedElements[times[i].first] = elements[i]; }
		tree.build(positionedElements);
	}

	template<typename... Arguments> void update_sub_tree(const std::size_t& i, const Arguments& ... rest) { tree.change(times[i].first, times[i].second, rest...); }

	template<typename... Arguments> void update_path(std::size_t u, std::size_t v, const Arguments& ... rest)
	{
		path(u, v, [this, &rest...](const std::size_t& low, const std::size_t& high)
		{ tree.change(low, high, rest...); });
	}

	auto range(const std::size_t& i) { return tree.range(times[i].first, times[i].second); }

	auto range(const std::size_t& u, const std::size_t& v)
	{
		auto result{tree.f.identity};
		path(u, v, [this, &result](const std::size_t& left, const std::size_t& right)
		{ result = tree.f.merge(result, tree.range(left, right)); });
		return tree.f.return_value(result);
	}
};


#endif