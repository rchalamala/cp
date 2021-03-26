#ifndef TIMER_H
#define TIMER_H

#include <chrono>

class Timer {
  std::chrono::time_point<std::chrono::high_resolution_clock> m_start;

 public:
  Timer();

  void reset();

  [[nodiscard]] long double elapsed() const;
};

#endif