#ifndef SPEED_HPP
#define SPEED_HPP

#include <ios>
#include <iostream>

inline bool speed()
{
	std::cin.exceptions(std::istream::failbit);
	std::cin.tie(nullptr);
	return std::ios_base::sync_with_stdio(false);
}

#endif