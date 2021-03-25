#ifndef OPTIMIZED_TRIAL_DIVISION_PRIMALITY_TEST_HPP
#define OPTIMIZED_TRIAL_DIVISION_PRIMALITY_TEST_HPP

namespace primality
{
	template<typename T> bool optimized_trial_division(const T& n)
	{
		static_assert(std::is_integral_v < T > );
		if(n <= 1)
		{ return false; }
		if(n <= 3)
		{ return true; }
		if(n % 2 == 0 || n % 3 == 0)
		{ return false; }
		for(T i = 5; i * i <= n; i += 6)
		{
			if(n % i == 0)
			{ return false; }
			if(n % (i + 2) == 0)
			{ return false; }
		}
		return true;
	}
}

#endif