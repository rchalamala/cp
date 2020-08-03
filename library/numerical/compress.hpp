#ifndef COMPRESS_HPP
#define COMPRESS_HPP

// Verification:
//

#include "../general/chash.hpp"
#include <ext/pb_ds/assoc_container.hpp>
#include <set>
#include <vector>

template<typename T> std::size_t compress(std::vector<T>& elements)
{
	std::set<T> orderedElements;
	for(const auto& element : elements) orderedElements.insert(element);
	__gnu_pbds::gp_hash_table<T, std::size_t, chash> indices;
	std::size_t index = 0;
	for(const auto& element : orderedElements) indices[element] = index++;
	for(auto& element : elements) element = indices[element];
	return index;
}

#endif