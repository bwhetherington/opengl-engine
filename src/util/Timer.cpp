#include "Timer.h"
#include <GLFW/glfw3.h>

Timer::Timer(double interval, std::function<void(double)> handler) {
  m_interval = interval;
  m_handler = handler;
  m_last_time = 0;
  m_last_handle = 0;
  m_timer = 0;
}

void Timer::step() {
  auto time = glfwGetTime();
  auto dt = time - m_last_time;
  m_last_time = time;

  m_timer += dt;
  if (m_timer >= m_interval) {
    m_timer -= m_interval;
    m_handler(time - m_last_handle);
    m_last_handle = time;
  }
}