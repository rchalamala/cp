#ifndef OUTPUT_HPP
#define OUTPUT_HPP

#include "to_string.hpp"
#include <ostream>

template<typename Argument, typename... Arguments> void print(const Argument& first, const Arguments& ... rest);

template<typename Argument, typename... Arguments> void printn(const Argument& first, const Arguments& ... rest);

template<typename Argument, typename... Arguments> void prints(const Argument& first, const Arguments& ... rest);

template<typename T> void print(const T& element);

inline void printn();

inline void prints();

template<typename T> void print(const T& element) { std::cout << std::to_string(element); }

inline void printn() { print('\n'); }

inline void prints() { print('\n'); }

template<typename Argument, typename... Arguments> void print(const Argument& first, const Arguments& ... rest)
{
	print(first);
	print(rest...);
}

template<typename Argument, typename... Arguments> void printn(const Argument& first, const Arguments& ... rest)
{
	print(first);
	if(sizeof...(rest))
	{ prints(); }
	printn(rest...);
}

template<typename Argument, typename... Arguments> void prints(const Argument& first, const Arguments& ... rest)
{
	print(first);
	if(sizeof...(rest))
	{ print(" "); }
	prints(rest...);
}

#endif