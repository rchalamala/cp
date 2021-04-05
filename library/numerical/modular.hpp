#ifndef MODULAR_HPP
#define MODULAR_HPP

// https://codeforces.com/contest/585/submission/24552744/
// https://codeforces.com/contest/1261/submission/65632855
// https://cp-algorithms.com/algebra/module-inverse.html
// Verification:
//

#include <cassert>
#include <cstddef>
#include <cstdint>
#include <string>
#include <type_traits>
#include <vector>

#include "gcd.hpp"

template<class T> class Modular
{
	using Type = typename std::decay<decltype(T::value)>::type;

	Type value{};

public:
	template<typename T1> Modular(const T1& element) : value{normalize(element)}
	{
		static_assert(std::is_integral<T>::value);
		static_assert(std::is_signed<T>::value);
	}

	const Type& operator()() const
	{
		return value;
	}

	template<typename T1> explicit operator T1() const
	{
		return static_cast<T1>(value);
	}

	constexpr static Type modulus()
	{
		return T::value;
	}

	template<typename T1> static Type normalize(const T1& element)
	{
		Type result{-modulus() <= element && element < modulus() ? static_cast<Type>(element) : static_cast<Type>(element % modulus())};
		if(result < 0)
		{ result += modulus(); }
		return result;
	}

	Modular& operator+=(const Modular& other)
	{
		if((value += other()) >= modulus())
		{ value -= modulus(); }
		return *this;
	}

	template<typename T1> Modular& operator+=(const T1& other)
	{
		return *this += Modular(other);
	}

	Modular& operator-=(const Modular& other)
	{
		if((value -= other()) < 0)
		{ value += modulus(); }
		return *this;
	}

	template<typename T1> Modular& operator-=(const T1& other)
	{
		return *this -= Modular(other);
	}

	Modular operator-() const
	{
		return Modular(-value);
	}

	template<typename T1 = T> typename std::enable_if<(sizeof(typename Modular<T1>::Type) >= 8), Modular&>::type& operator*=(const Modular& rhs)
	{
		static_assert(sizeof(T1) >= 8);
		auto quotient = static_cast<typename Modular<T1>::Type>(
				static_cast<long double>(value) * rhs.value / modulus());
		value = normalize(value * rhs.value - quotient * modulus());
		return *this;
	}

	template<typename T1 = T> typename std::enable_if<(sizeof(typename Modular<T1>::Type) < 8), Modular&>::type& operator*=(const Modular& rhs)
	{
		value = normalize<std::int64_t>(static_cast<std::int64_t>(value) * rhs());
		return *this;
	}

	template<typename T1> Modular& operator*=(const T1& other)
	{
		return *this *= Modular(other);
	}

	Modular& operator/=(const Modular& other)
	{
		return *this *= multiplicative_inverse(other());
	}

	template<typename T1> Modular& operator/=(const T1& other)
	{
		return *this /= Modular(other);
	}

	Modular& operator^=(const Modular& other)
	{
		assert(other() >= 0);
		Modular result(1);
		Type exponent = other();
		while(exponent)
		{
			if(exponent % 2)
			{ result *= *this; }
			*this *= *this;
			exponent /= 2;
		}
		return *this = result;
	}

	template<typename T1> Modular& operator^=(const T1& other)
	{
		return *this ^= Modular(other);
	}

	Modular& operator++()
	{
		if((*this += 1) == modulus())
		{ *this = 0; }
		return *this;
	}

	Modular& operator--()
	{
		if((*this -= 1) == -1)
		{ *this = modulus() - 1; }
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

	Type multiplicative_inverse(const Type& element)
	{
		auto gcd = extended_euclidian_gcd(normalize(element), modulus());
		assert(std::get<2>(gcd) == 1);
		return normalize(std::get<0>(gcd));
	}

	std::vector<Type> multiplicative_inverses(const Type& bound = modulus())
	{
		assert(bound > 1);
		std::vector<Type> inverses(bound);
		inverses[0] = 0;
		inverses[1] = 1;
		for(std::size_t i = 2; i < bound; ++i)
		{
			inverses[i] = (modulus() - (modulus() / i) * inverses[modulus() % i] % modulus()) % modulus();
		}
		return inverses;
	}

	template<typename T1> friend std::istream& operator>>(std::istream&, Modular<T1>& element);
};

template<typename T> Modular<T> operator-(Modular<T> lhs, const Modular<T>& rhs)
{
	return lhs -= rhs;
}

template<typename T1, typename T2> Modular<T1> operator-(Modular<T1> lhs, const T2& rhs)
{
	return lhs -= rhs;
}

template<typename T1, typename T2> Modular<T1> operator-(const T2& lhs, Modular<T1> rhs)
{
	return rhs -= lhs;
}

template<typename T> Modular<T> operator*(Modular<T> lhs, const Modular<T>& rhs)
{
	return lhs *= rhs;
}

template<typename T1, typename T2> Modular<T1> operator*(Modular<T1> lhs, const T2& rhs)
{
	return lhs *= rhs;
}

template<typename T1, typename T2> Modular<T1> operator*(const T2& lhs, Modular<T1> rhs)
{
	return rhs *= lhs;
}

template<typename T> Modular<T> operator/(Modular<T> lhs, const Modular<T>& rhs)
{
	return lhs /= rhs;
}

template<typename T1, typename T2> Modular<T1> operator/(Modular<T1> lhs, const T2& rhs)
{
	return lhs /= rhs;
}

template<typename T1, typename T2> Modular<T1> operator/(const T2& lhs, Modular<T1> rhs)
{
	return rhs /= lhs;
}

template<typename T> Modular<T> operator^(Modular<T> lhs, const Modular<T>& rhs)
{
	return lhs ^= rhs;
}

template<typename T1, typename T2> Modular<T1> operator^(Modular<T1> lhs, const T2& rhs)
{
	return lhs ^= rhs;
}

template<typename T1, typename T2> Modular<T1> operator^(const T2& lhs, Modular<T1> rhs)
{
	return rhs ^= lhs;
}

template<typename T> bool operator==(const Modular<T>& lhs, const Modular<T>& rhs)
{
	return lhs() == rhs();
}

template<typename T1, typename T2> bool operator==(const Modular<T1>& lhs, T2 rhs)
{
	return lhs == Modular<T1>(rhs);
}

template<typename T1, typename T2> bool operator==(T2 lhs, const Modular<T1>& rhs)
{
	return Modular<T1>(lhs) == rhs;
}

template<typename T> bool operator!=(const Modular<T>& lhs, const Modular<T>& rhs)
{
	return !(lhs == rhs);
}

template<typename T1, typename T2> bool operator!=(const Modular<T1>& lhs, T2 rhs)
{
	return !(lhs == rhs);
}

template<typename T1, typename T2> bool operator!=(T2 lhs, const Modular<T1>& rhs)
{
	return !(lhs == rhs);
}

template<typename T> bool operator<(const Modular<T>& lhs, const Modular<T>& rhs)
{
	return lhs() < rhs();
}

template<typename T1, typename T2> bool operator<(const Modular<T1>& lhs, T2 rhs)
{
	return lhs < Modular<T1>(rhs);
}

template<typename T1, typename T2> bool operator<(T2 lhs, const Modular<T1>& rhs)
{
	return Modular<T1>(lhs) < rhs;
}

template<typename T> bool operator>(const Modular<T>& lhs, const Modular<T>& rhs)
{
	return lhs() > rhs();
}

template<typename T1, typename T2> bool operator>(const Modular<T1>& lhs, T2 rhs)
{
	return lhs > Modular<T1>(rhs);
}

template<typename T1, typename T2> bool operator>(T2 lhs, const Modular<T1>& rhs)
{
	return Modular<T1>(lhs) > rhs;
}

template<typename T> bool operator<=(const Modular<T>& lhs, const Modular<T>& rhs)
{
	return !(lhs() > rhs());
}

template<typename T1, typename T2> bool operator<=(const Modular<T1>& lhs, T2 rhs)
{
	return !(lhs > Modular<T1>(rhs));
}

template<typename T1, typename T2> bool operator<=(T2 lhs, const Modular<T1>& rhs)
{
	return !(Modular<T1>(lhs) > rhs);
}

template<typename T> bool operator>=(const Modular<T>& lhs, const Modular<T>& rhs)
{
	return !(lhs() < rhs());
}

template<typename T1, typename T2> bool operator>=(const Modular<T1>& lhs, T2 rhs)
{
	return !(lhs < Modular<T1>(rhs));
}

template<typename T1, typename T2> bool operator>=(T2 lhs, const Modular<T1>& rhs)
{
	return !(Modular<T1>(lhs) < rhs);
}

namespace std
{
	template<typename T> std::string to_string(const Modular<T>& number)
	{
		return std::to_string(number());
	}
}  // namespace std

template<typename T> std::istream& operator>>(std::istream& stream, Modular<T>& element)
{
	stream >> element.value;
	element.value = Modular<T>::normalize(element.value);
	return stream;
}

template<typename T> std::ostream& operator<<(std::ostream& stream, const Modular<T>& element)
{
	return stream << element();
}

using ModulusType = std::int64_t;

constexpr ModulusType MOD1 = static_cast<long long>(1000000007);
constexpr ModulusType MOD2 = static_cast<long long>(998244353);

struct MODULUS
{
	static ModulusType value;
};
ModulusType MODULUS::value;
using VariableModulus = Modular<MODULUS>;

struct StaticModulus1
{
	constexpr static ModulusType value{MOD1};
};
struct StaticModulus2
{
	constexpr static ModulusType value{MOD2};
};

#endif