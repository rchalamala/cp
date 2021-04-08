#ifndef MODULAR_HPP
#define MODULAR_HPP

#include <algorithm>
#include <cstdint>
#include <type_traits>

template<typename T> T inverse(T a, T m)
{
	if(a == 1)
	{ return 1; }
	T u = 0, v = 1;
	while(a != 0)
	{
		T t = m / a;
		m -= t * a;
		std::swap(a, m);
		u -= t * v;
		std::swap(u, v);
	}
	return u;
}

// https://github.com/the-tourist/algo/blob/master/numeric/mint.cpp
template<typename MODULUS, std::enable_if_t<std::is_integral_v<std::decay_t<decltype(MODULUS::value)>> && std::is_signed_v<std::decay_t<decltype(MODULUS::value)>>, bool> = true> class Modulo
{
	using Type = typename std::decay_t<decltype(MODULUS::value)>;

	Type value{};

	template<typename T> static T normalize(const T& element)
	{
		Type result{};
		if(-modulus() < element && element < modulus())
		{
			result = element;
		}
		if(result < 0)
		{ result += modulus(); }
		return result;
	}

public:
	constexpr static Type modulus() { return MODULUS::value; }

	Modulo() {}

	template<typename T> Modulo(const T& uValue) : value{normalize(static_cast<Type>(uValue))} {}

	const Type& operator()() const { return value; }

	template<typename T> explicit operator T() { return static_cast<T>(value); }

	Modulo operator-() const { return Modulo{modulus() - value}; }

	Modulo operator~() const { return Modulo{inverse(value, modulus())}; }

	Modulo& operator++()
	{
		if(++value == modulus())
		{ value = 0; }
		return *this;
	}

	Modulo& operator++(int)
	{
		Modulo result{*this};
		++*this;
		return result;
	}

	Modulo& operator--()
	{
		if(value == 0)
		{ value = modulus(); }
		--value;
		return *this;
	}

	Modulo& operator--(int)
	{
		Modulo result{*this};
		--*this;
		return result;
	}

	Modulo& operator+=(const Modulo& other)
	{
		if((value -= (modulus() - other.value)) < 0)
		{ value += modulus(); }
		return *this;
	}

	template<typename T> Modulo& operator+=(const T& other) { return *this += Modulo{other}; }

	Modulo& operator-=(const Modulo& other)
	{
		if((value -= other.value) < 0)
		{ value += modulus(); }
		return *this;
	}

	template<typename T> Modulo& operator-=(const T& other) { return *this -= Modulo{other}; }

	Modulo& operator*=(const Modulo& other)
	{
		value = static_cast<Type>(static_cast<std::int64_t>(value) * other.value % modulus());
		return *this;
	}

	template<typename T> Modulo& operator*=(const T& other) { return *this *= Modulo{other}; }

	Modulo& operator/=(const Modulo& other) { return *this *= ~other; }

	template<typename T> Modulo& operator/=(const T& other) { return *this /= Modulo{other}; }

	template<typename T> friend bool operator==(const Modulo<T>& lhs, const Modulo<T>& rhs);

	template<typename T> friend bool operator<(const Modulo<T>& lhs, const Modulo<T>& rhs);

	template<typename T> friend bool operator>(const Modulo<T>& lhs, const Modulo<T>& rhs);

	template<typename T> friend std::istream& operator>>(std::istream& in, Modulo<T>& element);
};

template<typename T> bool operator==(const Modulo<T>& lhs, const Modulo<T>& rhs) { return lhs.value == rhs.value; }
template<typename T1, typename T2> bool operator==(const Modulo<T1>& lhs, const T2& rhs) { return lhs == Modulo<T1>{rhs}; }
template<typename T1, typename T2> bool operator==(const T1& lhs, const Modulo<T2>& rhs) { return Modulo<T2>{lhs} == rhs; }

template<typename T1, typename T2> bool operator!=(const T1& lhs, const T2& rhs) { return !(lhs == rhs); }

template<typename T> bool operator<(const Modulo<T>& lhs, const Modulo<T>& rhs) { return lhs.value < rhs.value; }
template<typename T1, typename T2> bool operator<(const Modulo<T1>& lhs, const T2& rhs) { return lhs < Modulo<T1>{rhs}; }
template<typename T1, typename T2> bool operator<(const T1& lhs, const Modulo<T2>& rhs) { return Modulo<T2>{lhs} < rhs; }

template<typename T> bool operator>(const Modulo<T>& lhs, const Modulo<T>& rhs) { return lhs.value > rhs.value; }
template<typename T1, typename T2> bool operator>(const Modulo<T1>& lhs, const T2& rhs) { return lhs > Modulo<T1>{rhs}; }
template<typename T1, typename T2> bool operator>(const T1& lhs, const Modulo<T2>& rhs) { return Modulo<T2>{lhs} > rhs; }

template<typename T1, typename T2> bool operator<=(const T1& lhs, const T2& rhs) { return !(lhs > rhs); }

template<typename T1, typename T2> bool operator>=(const T1& lhs, const T2& rhs) { return !(lhs < rhs); }

template<typename T> Modulo<T> operator+(const Modulo<T>& lhs, const Modulo<T>& rhs) { return Modulo<T>{lhs} += rhs; }
template<typename T1, typename T2> Modulo<T1> operator+(const Modulo<T1>& lhs, const T2& rhs) { return Modulo<T1>{lhs} += rhs; }
template<typename T1, typename T2> Modulo<T2> operator+(const T1& lhs, const Modulo<T2>& rhs) { return Modulo<T2>{lhs} += rhs; }

template<typename T> Modulo<T> operator-(const Modulo<T>& lhs, const Modulo<T>& rhs) { return Modulo<T>{lhs} -= rhs; }
template<typename T1, typename T2> Modulo<T1> operator-(const Modulo<T1>& lhs, const T2& rhs) { return Modulo<T1>{lhs} -= rhs; }
template<typename T1, typename T2> Modulo<T2> operator-(const T1& lhs, const Modulo<T2>& rhs) { return Modulo<T2>{lhs} -= rhs; }

template<typename T> Modulo<T> operator*(const Modulo<T>& lhs, const Modulo<T>& rhs) { return Modulo<T>{lhs} *= rhs; }
template<typename T1, typename T2> Modulo<T1> operator*(const Modulo<T1>& lhs, const T2& rhs) { return Modulo<T1>{lhs} *= rhs; }
template<typename T1, typename T2> Modulo<T2> operator*(const T1& lhs, const Modulo<T2>& rhs) { return Modulo<T2>{lhs} *= rhs; }

template<typename T> Modulo<T> operator/(const Modulo<T>& lhs, const Modulo<T>& rhs) { return Modulo<T>{lhs} /= rhs; }
template<typename T1, typename T2> Modulo<T1> operator/(const Modulo<T1>& lhs, const T2& rhs) { return Modulo<T1>{lhs} /= rhs; }
template<typename T1, typename T2> Modulo<T2> operator/(const T1& lhs, const Modulo<T2>& rhs) { return Modulo<T2>{lhs} /= rhs; }

template<typename T> std::istream& operator>>(std::istream& in, Modulo<T>& element)
{
	std::intmax_t value;
	in >> value;
	value %= T::value;
	if(value < 0)
	{ value += T::value; }
	element.value = static_cast<decltype(T::value)>(value);
	return in;
}

template<typename T> std::ostream& operator<<(std::ostream& out, const Modulo<T>& element) { return out << element(); }

namespace std
{
	template<typename T> std::string to_string(const Modulo<T>& element);
}  // namespace std

template<typename T> std::string std::to_string(const Modulo<T>& element) { return std::to_string(element()); }

// DIVISION AND FIX UP GCD WHEN NOT LAZY AND STATIC ASSERTIONS

#endif