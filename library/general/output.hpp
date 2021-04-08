#ifndef OUTPUT_HPP
#define OUTPUT_HPP

#include "to_string.hpp"
#include <ostream>

template<typename Argument, typename... Arguments> void print(std::ostream& out, const Argument& first, const Arguments& ... rest);

template<typename Argument, typename... Arguments> void printn(std::ostream& out, const Argument& first, const Arguments& ... rest);

template<typename Argument, typename... Arguments> void prints(std::ostream& out, const Argument& first, const Arguments& ... rest);

template<typename T> void print(std::ostream& out, const T& element);

inline void printn(std::ostream& out);

inline void prints(std::ostream& out);

template<typename T> void print(std::ostream& out, const T& element) { out << std::to_string(element); }

inline void printn(std::ostream& out) { print(out, '\n'); }

inline void prints(std::ostream& out) { print(out, '\n'); }

template<typename Argument, typename... Arguments> void print(std::ostream& out, const Argument& first, const Arguments& ... rest)
{
	print(out, first);
	print(out, rest...);
}

template<typename Argument, typename... Arguments> void printn(std::ostream& out, const Argument& first, const Arguments& ... rest)
{
	print(out, first);
	if(sizeof...(rest))
	{ prints(out); }
	printn(out, rest...);
}

template<typename Argument, typename... Arguments> void prints(std::ostream& out, const Argument& first, const Arguments& ... rest)
{
	print(out, first);
	if(sizeof...(rest))
	{ print(out, " "); }
	prints(out, rest...);
}

#endif