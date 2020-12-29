#ifndef AP_INTEGER
#define AP_INTEGER

#include <bits/stdc++.h>

template<typename T> class APInteger
{
	using Type = typename std::decay<decltype(T::base)>::type;
	std::vector<Type> digits;
	std::int8_t sign;
public:
	constexpr APInteger() : sign{1} {};

	APInteger(string value)
	{
		if(value.front() == '-')
		{
			sign = -1;
			value.erase(std::begin(value));
		}
		digits.resize(value.size());
		for(std::size_t i = 0; i < digits.size(); digits[i] = value[i], ++i);
	};

	template<typename T1> APInteger(T1 value)
	{
		sign = value < 0 ? -1 : 1;
		value *= sign;
		digits.resize(std::ceil(log(value) / log(T::base)));
		for(std::size_t i = 0; value; digits[i++] = value % T::base, value /= T::base);
		std::reverse(std::begin(digits), std::end(digits));
	}

	APInteger& operator+=(const APInteger& other)
	{
		if(sign == other.sign)
		{
			for(std::size_t i = 0, carry = 0; i < other.digits.size() || carry; ++i)
			{
				if(i == digits.size()) digits.push_back(0);
				digits[i] += carry + (i < other.digits.size() ? other.digits[i] : 0);
				carry = digits[i] >= T::base;
				if(carry) digits[i] -= T::base;
			}
		}
		else if(other) *this -= -other;
		return *this;
	}

	friend APInteger operator+(APInteger lhs, const APInteger& rhs) { return lhs += rhs; }

	APInteger& operator-=(const APInteger& other)
	{
		if(sign == other.sign)
		{
			if((sign == 1 && *this >= other) || (sign == -1 && *this <= other))
			{
				for(int i = 0, carry = 0; i < other.digits.size() || carry; ++i)
				{
					digits[i] -= carry + (i < other.digits.size() ? other.z[i] : 0);
					carry = digits[i] < 0;
					if(carry) digits[i] += T::base;
				}
				//trim();
			}
			else
			{
				*this = other - *this;
				this->sign = -this->sign;
			}
		}
		else if(other) *this += -other;
		return *this;
	}

	friend APInteger operator-(APInteger lhs, const APInteger& rhs) { return lhs -= rhs; }

};

template<typename T> APInteger<T> operator+(const APInteger<T>& lhs, const APInteger<T>& rhs) { return APInteger<T>(lhs) += rhs; }

template<typename T1, typename T2> APInteger<T1> operator+(const APInteger<T1>& lhs, T2 rhs) { return APInteger<T1>(lhs) += rhs; }

template<typename T1, typename T2> APInteger<T1> operator+(T2 lhs, const APInteger<T1>& rhs) { return APInteger<T1>(lhs) += rhs; }

template<typename T> APInteger<T> operator-(const APInteger<T>& lhs, const APInteger<T>& rhs) { return APInteger<T>(lhs) -= rhs; }

template<typename T1, typename T2> APInteger<T1> operator-(const APInteger<T1>& lhs, T2 rhs) { return APInteger<T1>(lhs) -= rhs; }

template<typename T1, typename T2> APInteger<T1> operator-(T2 lhs, const APInteger<T1>& rhs) { return APInteger<T1>(lhs) -= rhs; }

template<typename T> APInteger<T> operator*(const APInteger<T>& lhs, const APInteger<T>& rhs) { return APInteger<T>(lhs) *= rhs; }

template<typename T1, typename T2> APInteger<T1> operator*(const APInteger<T1>& lhs, T2 rhs) { return APInteger<T1>(lhs) *= rhs; }

template<typename T1, typename T2> APInteger<T1> operator*(T2 lhs, const APInteger<T1>& rhs) { return APInteger<T1>(lhs) *= rhs; }

template<typename T> APInteger<T> operator/(const APInteger<T>& lhs, const APInteger<T>& rhs) { return APInteger<T>(lhs) /= rhs; }

template<typename T1, typename T2> APInteger<T1> operator/(const APInteger<T1>& lhs, T2 rhs) { return APInteger<T1>(lhs) /= rhs; }

template<typename T1, typename T2> APInteger<T1> operator/(T2 lhs, const APInteger<T1>& rhs) { return APInteger<T1>(lhs) /= rhs; }

template<typename T> APInteger<T> operator^(const APInteger<T>& lhs, const APInteger<T>& rhs) { return APInteger<T>(lhs) ^= rhs; }

template<typename T1, typename T2> APInteger<T1> operator^(const APInteger<T1>& lhs, T2 rhs) { return APInteger<T1>(lhs) ^= rhs; }

template<typename T1, typename T2> APInteger<T1> operator^(T2 lhs, const APInteger<T1>& rhs) { return APInteger<T1>(lhs) ^= rhs; }

template<typename T> bool operator==(const APInteger<T>& lhs, const APInteger<T>& rhs) { return lhs() == rhs(); }

template<typename T1, typename T2> bool operator==(const APInteger<T1>& lhs, T2 rhs) { return lhs == APInteger<T1>(rhs); }

template<typename T1, typename T2> bool operator==(T2 lhs, const APInteger<T1>& rhs) { return APInteger<T1>(lhs) == rhs; }

template<typename T> bool operator!=(const APInteger<T>& lhs, const APInteger<T>& rhs) { return !(lhs == rhs); }

template<typename T1, typename T2> bool operator!=(const APInteger<T1>& lhs, T2 rhs) { return !(lhs == rhs); }

template<typename T1, typename T2> bool operator!=(T2 lhs, const APInteger<T1>& rhs) { return !(lhs == rhs); }

template<typename T> bool operator<(const APInteger<T>& lhs, const APInteger<T>& rhs) { return lhs() < rhs(); }

template<typename T1, typename T2> bool operator<(const APInteger<T1>& lhs, T2 rhs) { return lhs < APInteger<T1>(rhs); }

template<typename T1, typename T2> bool operator<(T2 lhs, const APInteger<T1>& rhs) { return APInteger<T1>(lhs) < rhs; }

template<typename T> bool operator>(const APInteger<T>& lhs, const APInteger<T>& rhs) { return lhs() > rhs(); }

template<typename T1, typename T2> bool operator>(const APInteger<T1>& lhs, T2 rhs) { return lhs > APInteger<T1>(rhs); }

template<typename T1, typename T2> bool operator>(T2 lhs, const APInteger<T1>& rhs) { return APInteger<T1>(lhs) > rhs; }

template<typename T> bool operator<=(const APInteger<T>& lhs, const APInteger<T>& rhs) { return !(lhs() > rhs()); }

template<typename T1, typename T2> bool operator<=(const APInteger<T1>& lhs, T2 rhs) { return !(lhs > APInteger<T1>(rhs)); }

template<typename T1, typename T2> bool operator<=(T2 lhs, const APInteger<T1>& rhs) { return !(APInteger<T1>(lhs) > rhs); }

template<typename T> bool operator>=(const APInteger<T>& lhs, const APInteger<T>& rhs) { return !(lhs() < rhs()); }

template<typename T1, typename T2> bool operator>=(const APInteger<T1>& lhs, T2 rhs) { return !(lhs < APInteger<T1>(rhs)); }

template<typename T1, typename T2> bool operator>=(T2 lhs, const APInteger<T1>& rhs) { return !(APInteger<T1>(lhs) < rhs); }

namespace std
{
	template<typename T> std::string to_string(const APInteger<T>& number)
	{
		std::string result;
		for(auto& digit : number) result.push_back(std::to_string(digit));;
		return result;
	}
}

#endif