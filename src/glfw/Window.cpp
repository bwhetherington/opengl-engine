#include "Window.h"

Window::Window(const char* name, unsigned int width, unsigned int height) {
  m_window = glfwCreateWindow(width, height, name, nullptr, nullptr);
}

Window::~Window() {
  glfwDestroyWindow(m_window);
  glfwTerminate();
}

void Window::makeContextCurrent() { glfwMakeContextCurrent(m_window); }

void Window::swapBuffers() { glfwSwapBuffers(m_window); }

void Window::setSwapInterval(int interval) { glfwSwapInterval(interval); }

void Window::setHint(int hint, int value) { glfwWindowHint(hint, value); }

void Window::setInputMode(int mode, int value) {
  glfwSetInputMode(m_window, mode, value);
}

void Window::pollEvents() { glfwPollEvents(); }

int Window::getKey(int key) const { return glfwGetKey(m_window, key); }

bool Window::shouldClose() const { return glfwWindowShouldClose(m_window); }
