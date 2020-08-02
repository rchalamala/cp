#ifndef HEAPSORT_HPP
#define HEAPSORT_HPP

// Verification:
// https://leetcode.com/submissions/detail/374366440/

#include <cstddef>
#include <functional>
#include <queue>
#include <vector>

template<typename T>
void sort(std::vector<T>& elements)
{
	std::priority_queue<T, std::vector<T>, std::greater<T>> next;
	for (const auto& element : elements) next.push(element);
	std::size_t i = 0;
	while (!next.empty())
	{
		elements[i++] = next.top();
		next.pop();
	}
}

#endif
