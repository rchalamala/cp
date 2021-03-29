#ifndef INPUT_HPP
#define INPUT_HPP

#include <array>
#include <complex>
#include <istream>
#include <string>
#include <utility>
#include <vector>

template<typename Argument, typename... Arguments> bool read(std::istream& in, Argument& first, Arguments& ... rest);

template<typename T, std::size_t N> bool read(std::istream& in, std::array<T, N>& elements);

template<typename T1, typename T2> bool read(std::istream& in, std::pair<T1, T2>& element);

template<typename T> bool read(std::istream& in, T& element);

template<typename T> bool read(std::istream& in, std::complex<T>& element);

template<typename T> bool read(std::istream& in, std::vector<T>& elements);

template<typename Argument, typename... Arguments> bool read(std::istream& in, Argument& first, Arguments& ... rest)
{
	bool result = true;
	result &= read(in, first);
	result &= read(in, rest...);
	return result;
}

template<typename T, std::size_t Size> bool read(std::istream& in, std::array<T, Size>& elements)
{
	bool result = true;
	for(T& element : elements)
	{ result &= read(in, element); }
	return result;
}

template<typename T1, typename T2> bool read(std::istream& in, std::pair<T1, T2>& element)
{
	return read(in, element.first, element.second);
}

template<typename T> bool read(std::istream& in, T& element)
{
	return static_cast<bool>(in >> element);
}

template<typename T> bool read(std::istream& in, std::complex<T>& element)
{
	bool result = true;
	T first, second;
	result &= read(in, first, second);
	element = std::complex<T>(first, second);
	return result;
}

template<typename T> bool read(std::istream& in, std::vector<T>& elements)
{
	bool result = true;
	for(T& element : elements)
	{ result &= read(in, element); }
	return result;
}

#endif