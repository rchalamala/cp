#ifndef TRIAL_DIVISION_PRIMALITY_TEST_HPP
#define TRIAL_DIVISION_PRIMALITY_TEST_HPP

namespace primality
{
	template<typename T> bool trial_division(const T& n)
	{
		static_assert(std::is_integral_v < T > );
		if(n <= 1)
		{ return false; }
		for(T i = 2; i * i <= n; ++i)
		{
			if(n % i == 0)
			{ return false; }
		}
		return true;
	}
}

#endif