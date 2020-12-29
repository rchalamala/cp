#ifndef DEBUG_HPP
#define DEBUG_HPP

// Verification:
//

#include <iostream>
#include <string>

// https://github.com/bqi343/USACO/blob/master/Implementations/content/contest/CppIO.h
template<typename Arg, typename... Args> void debug(const Arg& first, const Args& ... rest);

void debug();

template<typename Arg, typename... Args> void debug(const Arg& first, const Args& ... rest)
{
	std::cerr << std::to_string(first);
	if(sizeof...(rest)) std::cerr << ", ";
	debug(rest...);
}

void debug() { std::cerr << "]" << std::endl; }

#ifdef LOCAL
#define DEBUG(...) std::cerr << "LINE(" << __LINE__ << ") -> [" << #__VA_ARGS__ << "]: [", debug(__VA_ARGS__)
#else
#define DEBUG(...) 0
#endif

#endif