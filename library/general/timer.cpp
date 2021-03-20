// https://www.learncpp.com/cpp-tutorial/8-16-timing-your-code/
// Verification:
//

#include "timer.h"

#include <chrono>

Timer::Timer() : m_start{std::chrono::high_resolution_clock::now()} {}

void Timer::reset() { m_start = std::chrono::high_resolution_clock::now(); }

[[nodiscard]] long double Timer::elapsed() const {
  return std::chrono::duration_cast<
             std::chrono::duration<long double, std::ratio<1>>>(
             std::chrono::high_resolution_clock::now() - m_start)
      .count();
}