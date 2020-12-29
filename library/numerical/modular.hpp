#ifndef MODULAR_HPP
#define MODULAR_HPP

// Verification:
//

#include "gcd.hpp"
#include <cassert>
#include <cstddef>
#include <cstdint>
#include <iostream>
#include <string>
#include <type_traits>
#include <vector>

// https://codeforces.com/contest/1261/submission/65632855
// https://codeforces.com/contest/585/submission/24552744
template<typename T, typename = typename std::enable_if<std::is_integral<typename std::decay<decltype(T::value)>::type>::value && std::is_signed<typename std::decay<decltype(T::value)>::type>::value, typename std::decay<decltype(T::value)>::type>::type> class Modular
{
public:

	using Type = typename std::decay<decltype(T::value)>::type;

	constexpr Modular() : value{} {}

	template<typename T1> Modular(const T1& element) : value{normalize(element)} {}

	const Type& operator()() const { return value; }

	template<typename T1> explicit operator T1() const { return static_cast<T1>(value); }

	constexpr static Type modulus() { return T::value; }

	template<typename T1> static Type normalize(const T1& element)
	{
		Type result{-modulus() <= element && element < modulus() ? static_cast<Type>(element) : static_cast<Type>(element % modulus())};
		if(result < 0) result += modulus();
		return result;
	}

	Modular& operator+=(const Modular& other)
	{
		if((value += other()) >= modulus()) value -= modulus();
		return *this;
	}

	Modular& operator-=(const Modular& other)
	{
		if((value -= other()) < 0) value += modulus();
		return *this;
	}

	template<typename T1> Modular& operator+=(const T1& other) { return *this += Modular(other); }

	template<typename T1> Modular& operator-=(const T1& other) { return *this -= Modular(other); }

	Modular& operator++()
	{
		if((*this += 1) == modulus()) *this = 0;
		return *this;
	}

	Modular& operator--()
	{
		if((*this -= 1) == -1) *this = modulus() - 1;
		return *this;
	}

	Modular operator++(int)
	{
		Modular result(*this);
		++(*this);
		return result;
	}

	Modular operator--(int)
	{
		Modular result(*this);
		--(*this);
		return result;
	}

	const Modular operator-() const { return Modular(-value); }

	template<typename T1 = T> typename std::enable_if<(sizeof(typename Modular<T1>::Type) >= 8), Modular&>::type& operator*=(const Modular& rhs)
	{
		typename Modular<T1>::Type quotient = static_cast<typename Modular<T1>::Type>(static_cast<long double>(value) * rhs.value / modulus());
		value = normalize(value * rhs.value - quotient * modulus());
		return *this;
	}

	template<typename T1 = T> typename std::enable_if<(sizeof(typename Modular<T1>::Type) < 8), Modular&>::type& operator*=(const Modular& rhs)
	{
		value = normalize<std::int64_t>(static_cast<std::int64_t>(value) * rhs());
		return *this;
	}

	// https://cp-algorithms.com/algebra/module-inverse.html
	Type multiplicative_inverse(const Type& element)
	{
		auto gcd = extended_euclidian_gcd(normalize(element), modulus());
		assert(std::get<2>(gcd) == 1);
		return normalize(std::get<0>(gcd));
	}

	// https://cp-algorithms.com/algebra/module-inverse.html
	std::vector<Type> multiplicative_inverses(const Type& bound = modulus())
	{
		assert(bound > 1);
		std::vector<Type> inverses(bound);
		inverses[0] = 0;
		inverses[1] = 1;
		for(std::size_t i = 2; i < bound; ++i) inverses[i] = (modulus() - (modulus() / i) * inverses[modulus() % i] % modulus()) % modulus();
		return inverses;
	}

	Modular& operator/=(const Modular& other) { return *this *= multiplicative_inverse(other()); }

	Modular& operator^=(const Modular& other)
	{
		assert(other() >= 0);
		Modular result(1);
		Type exponent = other();
		while(exponent)
		{
			if(exponent % 2) result *= *this;
			*this *= *this;
			exponent /= 2;
		}
		return *this = result;
	}

	template<typename T1> friend bool operator==(const Modular<T1>& lhs, const Modular<T1>& rhs);

	template<typename T1> friend bool operator<(const Modular<T1>& lhs, const Modular<T1>& rhs);

	template<typename T1> friend bool operator>(const Modular<T1>& lhs, const Modular<T1>& rhs);

	template<typename T1> friend std::istream& operator>>(std::istream& stream, Modular<T1>& element);

private:
	Type value;
};

template<typename T> Modular<T> operator+(const Modular<T>& lhs, const Modular<T>& rhs) { return Modular<T>(lhs) += rhs; }

template<typename T1, typename T2> Modular<T1> operator+(const Modular<T1>& lhs, T2 rhs) { return Modular<T1>(lhs) += rhs; }

template<typename T1, typename T2> Modular<T1> operator+(T2 lhs, const Modular<T1>& rhs) { return Modular<T1>(lhs) += rhs; }

template<typename T> Modular<T> operator-(const Modular<T>& lhs, const Modular<T>& rhs) { return Modular<T>(lhs) -= rhs; }

template<typename T1, typename T2> Modular<T1> operator-(const Modular<T1>& lhs, T2 rhs) { return Modular<T1>(lhs) -= rhs; }

template<typename T1, typename T2> Modular<T1> operator-(T2 lhs, const Modular<T1>& rhs) { return Modular<T1>(lhs) -= rhs; }

template<typename T> Modular<T> operator*(const Modular<T>& lhs, const Modular<T>& rhs) { return Modular<T>(lhs) *= rhs; }

template<typename T1, typename T2> Modular<T1> operator*(const Modular<T1>& lhs, T2 rhs) { return Modular<T1>(lhs) *= rhs; }

template<typename T1, typename T2> Modular<T1> operator*(T2 lhs, const Modular<T1>& rhs) { return Modular<T1>(lhs) *= rhs; }

template<typename T> Modular<T> operator/(const Modular<T>& lhs, const Modular<T>& rhs) { return Modular<T>(lhs) /= rhs; }

template<typename T1, typename T2> Modular<T1> operator/(const Modular<T1>& lhs, T2 rhs) { return Modular<T1>(lhs) /= rhs; }

template<typename T1, typename T2> Modular<T1> operator/(T2 lhs, const Modular<T1>& rhs) { return Modular<T1>(lhs) /= rhs; }

template<typename T> Modular<T> operator^(const Modular<T>& lhs, const Modular<T>& rhs) { return Modular<T>(lhs) ^= rhs; }

template<typename T1, typename T2> Modular<T1> operator^(const Modular<T1>& lhs, T2 rhs) { return Modular<T1>(lhs) ^= rhs; }

template<typename T1, typename T2> Modular<T1> operator^(T2 lhs, const Modular<T1>& rhs) { return Modular<T1>(lhs) ^= rhs; }

template<typename T> bool operator==(const Modular<T>& lhs, const Modular<T>& rhs) { return lhs() == rhs(); }

template<typename T1, typename T2> bool operator==(const Modular<T1>& lhs, T2 rhs) { return lhs == Modular<T1>(rhs); }

template<typename T1, typename T2> bool operator==(T2 lhs, const Modular<T1>& rhs) { return Modular<T1>(lhs) == rhs; }

template<typename T> bool operator!=(const Modular<T>& lhs, const Modular<T>& rhs) { return !(lhs == rhs); }

template<typename T1, typename T2> bool operator!=(const Modular<T1>& lhs, T2 rhs) { return !(lhs == rhs); }

template<typename T1, typename T2> bool operator!=(T2 lhs, const Modular<T1>& rhs) { return !(lhs == rhs); }

template<typename T> bool operator<(const Modular<T>& lhs, const Modular<T>& rhs) { return lhs() < rhs(); }

template<typename T1, typename T2> bool operator<(const Modular<T1>& lhs, T2 rhs) { return lhs < Modular<T1>(rhs); }

template<typename T1, typename T2> bool operator<(T2 lhs, const Modular<T1>& rhs) { return Modular<T1>(lhs) < rhs; }

template<typename T> bool operator>(const Modular<T>& lhs, const Modular<T>& rhs) { return lhs() > rhs(); }

template<typename T1, typename T2> bool operator>(const Modular<T1>& lhs, T2 rhs) { return lhs > Modular<T1>(rhs); }

template<typename T1, typename T2> bool operator>(T2 lhs, const Modular<T1>& rhs) { return Modular<T1>(lhs) > rhs; }

template<typename T> bool operator<=(const Modular<T>& lhs, const Modular<T>& rhs) { return !(lhs() > rhs()); }

template<typename T1, typename T2> bool operator<=(const Modular<T1>& lhs, T2 rhs) { return !(lhs > Modular<T1>(rhs)); }

template<typename T1, typename T2> bool operator<=(T2 lhs, const Modular<T1>& rhs) { return !(Modular<T1>(lhs) > rhs); }

template<typename T> bool operator>=(const Modular<T>& lhs, const Modular<T>& rhs) { return !(lhs() < rhs()); }

template<typename T1, typename T2> bool operator>=(const Modular<T1>& lhs, T2 rhs) { return !(lhs < Modular<T1>(rhs)); }

template<typename T1, typename T2> bool operator>=(T2 lhs, const Modular<T1>& rhs) { return !(Modular<T1>(lhs) < rhs); }

namespace std { template<typename T> std::string to_string(const Modular<T>& number) { return std::to_string(number()); }}

template<typename T> std::istream& operator>>(std::istream& stream, Modular<T>& element)
{
	typename Modular<T>::Type value;
	stream >> value;
	element.value = Modular<T>::normalize(value);
	return stream;
}

template<typename T> std::ostream& operator<<(std::ostream& stream, const Modular<T>& element) { return stream << element(); }


using ModulusType = ll;

constexpr ModulusType MOD1 __attribute__((unused)) = static_cast<long long>(1000000007);
constexpr ModulusType MOD2 __attribute__((unused)) = static_cast<long long>(998244353);

struct MODULUS { static ModulusType value; };
ModulusType MODULUS::value;
using VariableModulus = Modular<MODULUS>;

struct StaticModulus1 { constexpr static ModulusType value{MOD1}; };
struct StaticModulus2 { constexpr static ModulusType value{MOD2}; };

#endif