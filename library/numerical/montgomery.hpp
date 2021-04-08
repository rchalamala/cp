#ifndef MONTGOMERY_HPP
#define MONTGOMERY_HPP

#include <cstdint>
#include <limits>
#include <type_traits>

#include "trailing_zero_bits.hpp"

/*//https://cp-algorithms.com/algebra/montgomery_multiplication.html
template<typename T1, typename T2, std::size_t Bits> struct BigMultiplication
{
	static_assert(std::is_integral_v<T1>);
	static_assert(std::is_integral_v<T2>);
	static_assert(std::is_unsigned_v<T1>);
	static_assert(std::is_unsigned_v<T2>);

	T1 high, low;

	static BigMultiplication multiply(const T1& x, const T1& y)
	{
		T2 a = x >> Bits, b = x, c = y >> Bits, d = y;
		T1 ac = static_cast<T1>(a) * c, ad = static_cast<T1>(a) * d, bc = static_cast<T1>(b) * c, bd = static_cast<T1>(b) * d;
		T1 carry = static_cast<T1>(static_cast<T2>(ad)) + static_cast<T1>(static_cast<T2>(bc)) + (bd >> Bits);
		T1 high = ac + (ad >> Bits) + (bc >> Bits) + (carry >> Bits);
		T1 low = (ad << Bits) + (bc << Bits) + bd;
		return {high, low};
	}
};

template<typename T1, typename T2, std::size_t Bits> struct Montgomery
{

	T1 n;

	static T1 modulus, inverse;

	static T1 redc(const BigMultiplication<T1, T2, Bits>& x)
	{
		T1 q = x.low * inverse, a = BigMultiplication<T1, T2, Bits>::multiply(q, modulus).high;
		return (x.high < a ? (x.high + modulus - q) : x.high - q);
	}

	static void set_modulus(const T1& uModulus)
	{
		modulus = uModulus;
		inverse = 1;
		for(std::size_t i = 0; i < __builtin_ctzll(Bits); ++i)
		{ inverse *= 2 - modulus * inverse; }
	}

	explicit Montgomery(const T1& uN) : n{uN}
	{
		n %= modulus;
		for(std::size_t i = 0; i < Bits; i++)
		{
			n <<= 1;
			if(n >= modulus)
			{
				n -= modulus;
			}
		}
	}

	T1 value() const
	{
		return redc({0, n});
	}

	Montgomery& operator+=(const Montgomery& other)
	{
		n += other.n;
		if(n >= modulus)
		{ n -= modulus; }
		return *this;
	}

	template<typename U> Montgomery& operator+=(const U& other)
	{
		n += other;
		if(n >= modulus)
		{ n -= modulus; }
		return *this;
	}

	template<typename U> Montgomery& operator+(const U& other)
	{
		return Montgomery{*this} += other;
	}

	Montgomery& operator*=(const Montgomery& other)
	{
		n = redc(BigMultiplication<T1, T2, Bits>::multiply(n, other.n));
		return *this;
	}

	template<typename U> Montgomery& operator*=(const U& other)
	{
		n *= Montgomery{other};
		return *this;
	}

	template<typename U> Montgomery& operator*(const U& other)
	{
		return Montgomery{*this} *= other;
	}

};

template<typename T1, typename T2, std::size_t Bits> T1 Montgomery<T1, T2, Bits>::modulus{};
template<typename T1, typename T2, std::size_t Bits> T1 Montgomery<T1, T2, Bits>::inverse{};*/

// https://judge.yosupo.jp/submission/38126
struct Montgomery
{
	uint64_t n;
	static uint64_t modulus, inverse, r2;

	Montgomery() : n{} {}

	Montgomery(const uint64_t& uN) : n{redc(__uint128_t(uN) * r2)} {}

	static void set_modulus(const uint64_t& uModulus)
	{
		assert(uModulus >= 1 && uModulus - 1 < (std::numeric_limits<uint64_t>::max() >> 1));
		modulus = uModulus;
		inverse = 1;
		for(int i = 0; i < 6; i++)
		{ inverse *= 2 - inverse * modulus; }
		r2 = -__uint128_t(modulus) % modulus;
	}

	static uint64_t redc(const __uint128_t& x)
	{
		uint64_t y{uint64_t(x >> 64)}, l{uint64_t((__uint128_t(uint64_t(x) * inverse) * modulus) >> 64)};
		return y < l ? y + modulus - l : y - l;
	}

	Montgomery& operator+=(const Montgomery& other)
	{
		n += other.n;
		if(n >= modulus)
		{ n -= modulus; }
		return *this;
	}

	Montgomery& operator+(const Montgomery& other) const { return Montgomery(*this) += other; }

	Montgomery& operator*=(const Montgomery& other)
	{
		n = redc(__uint128_t(n) * other.n);
		return *this;
	}

	Montgomery& operator*(const Montgomery& other) const { return Montgomery(*this) *= other; }

	uint64_t value() const { return redc(n); }
};

uint64_t Montgomery::modulus{1}, Montgomery::inverse, Montgomery::r2;

#endif