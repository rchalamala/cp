#ifndef IO_HPP
#define IO_HPP

// Verification:
//

#include <array>
#include <bitset>
#include <complex>
#include <fstream>
#include <ios>
#include <iostream>
#include <string>
#include <sstream>
#include <tuple>
#include <utility>
#include <vector>

// https://github.com/bqi343/USACO/blob/master/Implementations/content/contest/CppIO.h
namespace std
{

	std::string to_string(const char& element) { return std::string(1, element); }

	std::string to_string(const char *element) { return std::string(element); }

	std::string to_string(const std::string& element) { return element; }

	std::string to_string(const bool& element)
	{
#ifdef LOCAL
		return element ? "true" : "false";
#else
		return std::string{static_cast<char>('0' + element)};
#endif
	}

	template<typename T> std::string to_string(const std::complex<T>& element)
	{
		std::stringstream convert;
		convert << element;
		return convert.str();
	}

	std::string to_string(const std::vector<bool>& elements)
	{
		std::string convert = "{";
		for(const auto& element : elements) convert += static_cast<char>('0' + element);
		return convert + "}";
	}

	template<std::size_t Size> std::string to_string(const std::bitset<Size>& elements)
	{
		std::string convert;
		for(auto i = 0; i < Size; ++i) convert += static_cast<char>('0' + elements[i]);
		return convert;
	}

	template<typename T1, typename T2> std::string to_string(std::pair<T1, T2> element)
	{
#ifdef LOCAL
		return "(" + std::to_string(element.first) + ", " + std::to_string(element.second) + ")";
#else
		return std::to_string(element.ff) + " " + std::to_string(element.ss);
#endif
	}

	template<typename T> std::string to_string(const T& elements)
	{
		std::string convert;
		bool first = true;
#ifdef LOCAL
		convert += "{";
		for (const auto& element : elements)
		{
			if (!first) convert += ", ";
			first = false;
			convert += std::to_string(element);
		}
		convert += "}";
#else
		for(const auto& element : elements)
		{
			if(!first) convert += " ";
			first = false;
			convert += std::to_string(element);
		}
#endif
		return convert;
	}
}

// INPUT
template<typename Arg, typename... Args> void read(std::istream& in, Arg& first, Args& ... rest);

template<typename T1, typename T2> void read(std::istream& in, std::pair<T1, T2>& element);

template<typename T, std::size_t Size> void read(std::istream& in, std::array<T, Size>& elements);

template<typename T> void read(std::istream& in, double& element);

template<typename T> void read(std::istream& in, long double& element);

template<typename T> void read(std::istream& in, std::complex<T>& element);

template<typename T> void read(std::istream& in, std::tuple<T, T, T, T, T, T>& element);

template<typename T> void read(std::istream& in, std::tuple<T, T, T, T, T>& element);

template<typename T> void read(std::istream& in, std::tuple<T, T, T, T>& element);

template<typename T> void read(std::istream& in, std::tuple<T, T, T>& element);

template<typename T> void read(std::istream& in, std::vector<T>& elements);

template<typename T> void read(std::istream& in, T& element);

template<typename Arg, typename... Args> void read(std::istream& in, Arg& first, Args& ... rest)
{
	read(in, first);
	read(in, rest...);
}

template<typename T1, typename T2> void read(std::istream& in, std::pair<T1, T2>& element) { read(in, element.first, element.second); }

template<typename T, std::size_t Size> void read(std::istream& in, std::array<T, Size>& elements) { for(auto& element : elements) read(in, element); }

void read(std::istream& in, double& element)
{
	std::string convert;
	read(in, convert);
	element = std::stod(convert);
}

void read(std::istream& in, long double& element)
{
	std::string convert;
	read(in, convert);
	element = std::stold(convert);
}

template<typename T> void read(std::istream& in, std::complex<T>& element)
{
	T first, second;
	read(in, first, second);
	element = std::complex<T>(first, second);
}

template<typename T> void read(std::istream& in, std::tuple<T, T, T, T, T, T>& element) { read(in, std::get<0>(element), std::get<1>(element), std::get<2>(element), std::get<3>(element), std::get<4>(element), std::get<5>(element)); }

template<typename T> void read(std::istream& in, std::tuple<T, T, T, T, T>& element) { read(in, std::get<0>(element), std::get<1>(element), std::get<2>(element), std::get<3>(element), std::get<4>(element)); }

template<typename T> void read(std::istream& in, std::tuple<T, T, T, T>& element) { read(in, std::get<0>(element), std::get<1>(element), std::get<2>(element), std::get<3>(element)); }

template<typename T> void read(std::istream& in, std::tuple<T, T, T>& element) { read(in, std::get<0>(element), std::get<1>(element), std::get<2>(element)); }

template<typename T> void read(std::istream& in, std::vector<T>& elements) { for(auto& element : elements) read(in, element); }

template<typename T> void read(std::istream& in, T& element) { in >> element; }

// OUTPUT
template<typename Arg, typename... Args> void print(std::ostream& out, const Arg& first, const Args& ... rest);

template<typename Arg, typename... Args> void prints(std::ostream& out, const Arg& first, const Args& ... rest);

template<typename T> void print(std::ostream& out, const T& element);

void prints(std::ostream& out);

template<typename Arg, typename... Args> void print(std::ostream& out, const Arg& first, const Args& ... rest)
{
	print(out, first);
	print(out, rest...);
}

template<typename Arg, typename... Args> void prints(std::ostream& out, const Arg& first, const Args& ... rest)
{
	print(out, first);
	if(sizeof...(rest)) print(out, " ");
	prints(out, rest...);
}

template<typename T> void print(std::ostream& out, const T& element) { out << std::to_string(element); }

void prints(std::ostream& out) { print(out, '\n'); }

void setIO()
{
	std::ios_base::sync_with_stdio(false);
	std::cin.tie(nullptr);
	std::cout.tie(nullptr);
#ifdef LOCAL
	std::cin.exceptions(std::ios::eofbit | std::ios::failbit | std::ios::badbit);
#endif
}

#endif