#ifndef DEBUG_H
#define DEBUG_H

// https://github.com/bqi343/USACO/blob/master/Implementations/content/contest/CppIO.h
// Verification:
//
#include <iostream>

template <typename Arg, typename... Args>
void debug(const Arg& first, const Args&... rest);

inline void debug();

template <typename Arg, typename... Args>
void debug(const Arg& first, const Args&... rest) {
	std::cerr << std::to_string(first);
	if (sizeof...(rest)) std::cerr << ", ";
	debug(rest...);
}

inline void debug() { std::cerr << "]" << std::endl; }

#ifdef LOCAL
#define DEBUG(...)                                                        \
  std::cerr << "LINE(" << __LINE__ << ") -> [" << #__VA_ARGS__ << "]: [", \
      debug(__VA_ARGS__)
#else
#define DEBUG(...) 0
#endif

#endif