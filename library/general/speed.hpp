#ifndef SPEED_HPP
#define SPEED_HPP

#include <iostream>

inline bool speed()
{
	std::cin.exceptions(std::cin.failbit);
	return std::cin.tie(nullptr) && std::ios_base::sync_with_stdio(false);
}

#endif