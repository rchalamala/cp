#ifndef QUADRATIC_DIOPHANTINE_HPP
#define QUADRATIC_DIOPHANTINE_HPP

template<typename T> class quadratic_diophantine
{
public:
	quadratic_diophantine(const T& a, const T& b, const T& c, const T& d, const T& e, const T& f)
	{
		assert(a || b || c);
	}

};

#endif