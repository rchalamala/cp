#ifndef TIMER_HPP
#define TIMER_HPP

#include <chrono>

// https://www.learncpp.com/cpp-tutorial/8-16-timing-your-code/
class Timer
{
	std::chrono::time_point<std::chrono::high_resolution_clock> m_start;
public:
	Timer()
			:m_start(std::chrono::high_resolution_clock::now())
	{
	}

	void reset()
	{
		m_start = std::chrono::high_resolution_clock::now();
	}

	long double elapsed() const
	{
		return std::chrono::duration_cast<std::chrono::duration<long double, std::ratio<1> >>(
				std::chrono::high_resolution_clock::now() - m_start).count();
	}
};

#endif