#ifndef INPUT_HPP
#define INPUT_HPP

// Verification:
//
#include <array>
#include <complex>
#include <istream>
#include <tuple>
#include <utility>
#include <vector>

inline bool read(std::istream& in, double& element);

inline bool read(std::istream& in, long double& element);

template <typename Argument, typename... Arguments>
bool read(std::istream& in, Argument& first, Arguments&... rest);

template <typename T, std::size_t Size>
bool read(std::istream& in, std::array<T, Size>& elements);

template <typename T1, typename T2>
bool read(std::istream& in, std::pair<T1, T2>& element);

template <typename T>
bool read(std::istream& in, T& element);

template <typename T>
bool read(std::istream& in, std::complex<T>& element);

template <typename T>
bool read(std::istream& in, std::tuple<T, T, T, T, T, T>& element);

template <typename T>
bool read(std::istream& in, std::tuple<T, T, T, T, T>& element);

template <typename T>
bool read(std::istream& in, std::tuple<T, T, T, T>& element);

template <typename T>
bool read(std::istream& in, std::tuple<T, T, T>& element);

template <typename T>
bool read(std::istream& in, std::vector<T>& elements);

inline bool read(std::istream& in, double& element) {
	bool result = true;
	std::string convert;
	result &= read(in, convert);
	element = std::stod(convert);
	return result;
}

inline bool read(std::istream& in, long double& element) {
	bool result = true;
	std::string convert;
	result &= read(in, convert);
	element = std::stold(convert);
	return result;
}

template <typename Argument, typename... Arguments>
bool read(std::istream& in, Argument& first, Arguments&... rest) {
	bool result = true;
	result &= read(in, first);
	result &= read(in, rest...);
	return result;
}

template <typename T, std::size_t Size>
bool read(std::istream& in, std::array<T, Size>& elements) {
	bool result = true;
	for (T& element : elements) result &= read(in, element);
	return result;
}

template <typename T1, typename T2>
bool read(std::istream& in, std::pair<T1, T2>& element) {
	return read(in, element.first, element.second);
}

template <typename T>
bool read(std::istream& in, T& element) {
	return static_cast<bool>(in >> element);
}

template <typename T>
bool read(std::istream& in, std::complex<T>& element) {
	bool result = true;
	T first, second;
	result &= read(in, first, second);
	element = std::complex<T>(first, second);
	return result;
}

template <typename T>
bool read(std::istream& in, std::tuple<T, T, T, T, T, T>& element) {
	return read(in, std::get<0>(element), std::get<1>(element),
	            std::get<2>(element), std::get<3>(element), std::get<4>(element),
	            std::get<5>(element));
}

template <typename T>
bool read(std::istream& in, std::tuple<T, T, T, T, T>& element) {
	return read(in, std::get<0>(element), std::get<1>(element),
	            std::get<2>(element), std::get<3>(element), std::get<4>(element));
}

template <typename T>
bool read(std::istream& in, std::tuple<T, T, T, T>& element) {
	return read(in, std::get<0>(element), std::get<1>(element),
	            std::get<2>(element), std::get<3>(element));
}

template <typename T>
bool read(std::istream& in, std::tuple<T, T, T>& element) {
	return read(in, std::get<0>(element), std::get<1>(element),
	            std::get<2>(element));
}

template <typename T>
bool read(std::istream& in, std::vector<T>& elements) {
	bool result = true;
	for (T& element : elements) result &= read(in, element);
	return result;
}

#endif