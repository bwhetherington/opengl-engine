#pragma once

#include <functional>

class Timer {
 private:
  std::function<void(double)> m_handler;
  double m_interval;
  double m_last_time;
  double m_timer;
  double m_last_handle;

 public:
  Timer(double interval, std::function<void(double)> handler);

  void step();
};