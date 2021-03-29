#ifndef MONTGOMERY_HPP
#define MONTGOMERY_HPP

#include <limits>
#include <type_traits>

#include "trailing_zero_bits.hpp"
/*
//https://cp-algorithms.com/algebra/montgomery_multiplication.html
template<typename T1, typename T2, std::size_t Bits> struct BigMultiplication
{
	static_assert(std::is_integral_v<T1>);
	static_assert(std::is_integral_v<T2>);
	static_assert(std::is_unsigned<T1>);
	static_assert(std::is_unsigned<T2>);

	T high, low;

	static BigMultiplication multiply(const T& x, const T& y)
	{
		T2 a = x >> Bits, b = x, c = y >> Bits, d = y;
		T1 ac = static_cast<T1>(a) * c, ad = static_cast<T1>(a) * d, T1 bc = static_cast<T1>(b) * c, bd = static_cast<T1>(b) * d;
		T carry = static_cast<T1>(static_cast<T2>(ad)) + static_cast<T1>(static_cast<T2>(bc)) + (bd >> Bits);
		T high = ac + (ad >> Bits) + (bc >> Bits) + (carry >> Bits);
		T low = (ad << Bits) + (bc << Bits) + bd;
		return {high, low};
	}
};

template<typename T1, typename T2, std::size_t Bits> struct Montgomery
{
	static_assert(std::is_integral_v<T>);

	T1 n;

	static T1 modulus, inverse{1};

	static T1 initialize(const T1& uN)
	{
		x %= mod;
		for (int i = 0; i < 128; i++) {
			x <<= 1;
			if (x >= mod)
				x -= mod;
		}
		return x;
	}

	static  redc(const BigMultiplication<T1, T2, Bits>& x)
	{
		T1 q = x.low * inverse, a = BigMultiplication<T1, T2, Bits>::multiply(q, modulus).high;
		return (x.high < a ? (x.high + modulus - q) : x.high - q);
	}

	static void set_modulus(const T1& uModulus)
	{
		modulus = uModulus;
		inverse = 1;
		for(std::uint_fast16_t i = 0; i < 6; ++i)
		{ inverse *= 2 - modulus * inverse; }
	}

	explicit Montgomery(const T1& uN) : n{initialize(uN)}
	{
	}

	T1 value() const
	{
		return redc(n);
	}

	Montgomery& operator+=(const Montgomery& other)
	{
		n += other.n;
		if(n >= modulus)
		{ n -= modulus; }
		return *this;
	}

	Montgomery& operator*=(const Montgomery& other)
	{
		n = redc(static_cast<uli>(n) * other.n);
		return *this;
	}

	Montgomery& operator+(const Montgomery& other)
	{
		return Montgomery(*this) += other;
	}

	Montgomery& operator*(const Montgomery& other)
	{
		return Montgomery(*this) += other;
	}

};

std::uint_fast64_t Montgomery::modulus{};
, Montgomery::inverse{
};
*/

// https://judge.yosupo.jp/submission/38126
struct Montgomery
{
	uint64_t n;
	static uint64_t modulus, inverse, r2;

	Montgomery() : n{0}
	{
	}

	Montgomery(const uint64_t& x) : n{init(x)}
	{
	}

	static uint64_t init(const uint64_t& w)
	{
		return redc(__uint128_t(w) * r2);
	}

	static void set_modulus(const uint64_t& m)
	{
		modulus = inverse = m;
		for(int i{}; i < 5; i++)
		{ inverse *= 2 - inverse * m; }
		r2 = -__uint128_t(m) % m;
	}

	static uint64_t redc(const __uint128_t& x)
	{
		uint64_t y{uint64_t(x >> 64) - uint64_t((__uint128_t(uint64_t(x) * inverse) * modulus) >> 64)};
		return int64_t(y) < 0 ? y + modulus : y;
	}

	Montgomery& operator+=(const Montgomery& other)
	{
		n += other.n - modulus;
		if(int64_t(n) < 0)
		{ n += modulus; }
		return *this;
	}

	Montgomery& operator+(const Montgomery& other) const
	{
		return Montgomery(*this) += other;
	}

	Montgomery& operator*=(const Montgomery& other)
	{
		n = redc(__uint128_t(n) * other.n);
		return *this;
	}

	Montgomery& operator*(const Montgomery& other) const
	{
		return Montgomery(*this) *= other;
	}

	uint64_t value() const
	{
		return redc(n);
	}
};

uint64_t Montgomery::modulus, Montgomery::inverse, Montgomery::r2;

#endif