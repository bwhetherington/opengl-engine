#pragma once

#include <GLFW/glfw3.h>

class Window {
 private:
  GLFWwindow* m_window;

 public:
  Window(const char* name, unsigned int width, unsigned int height);
  virtual ~Window();

  void makeContextCurrent();

  void swapBuffers();

  void setSwapInterval(int interval);

  void setHint(int hint, int value);

  void setInputMode(int mode, int value);

  void pollEvents();

  int getKey(int key) const;

  bool shouldClose() const;
};