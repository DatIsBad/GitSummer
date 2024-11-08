#pragma once
#include <stdlib.h>
#include <stdio.h>
#include <GL/glew.h>
#include <GLFW/glfw3.h>

#include "Observer.h"


class Controller
{
public:
	Controller(GLFWwindow* window, Observer* obj);
	~Controller();
	void change_observer(Observer* obj);
	void useKeys(int key, int scancode, int action, int mods);
	void useCursorPos( double x, double y);

	static void key_callback(GLFWwindow* window, int key, int scancode, int action, int mods);
	static void error_callback(int error, const char* description);
	static void window_focus_callback(GLFWwindow* window, int focused);
	static void window_iconify_callback(GLFWwindow* window, int iconified);
	static void window_size_callback(GLFWwindow* window, int width, int height);
	static void cursor_callback(GLFWwindow* window, double x, double y);
	static void button_callback(GLFWwindow* window, int button, int action, int mode);

private:
	Observer* m_obj;
	GLFWwindow* m_window;
	bool locked;
};

