#include <ball.hpp>

#include <iostream>

#include <GLFW/glfw3.h>

#include <glm/glm.hpp>

void error_callback(int error, const char* description) {
	fprintf(stderr, "Error: %s\n", description);
}

void window_close_callback(GLFWwindow* window) {
	std::cout << "Closing window!" << std::endl;
}

void key_callback(GLFWwindow* window, int key, int scancode, int action, int mods) {
	std::cout << "key = " << key
			  << ", scancode = " << scancode
			  << ", action = " << action
			  << ", mods = " << mods
			  << std::endl;
	
	if (GLFW_KEY_ESCAPE == key && GLFW_PRESS == action) {
		std::cout << "Closing window!" << std::endl;
		glfwSetWindowShouldClose(window, GLFW_TRUE);
	}
}

int main() {
	glfwSetErrorCallback(error_callback);
	
	if (!glfwInit()) {
		exit(EXIT_FAILURE);
	}
	
	glfwWindowHint(GLFW_CONTEXT_VERSION_MAJOR, 3);
	glfwWindowHint(GLFW_CONTEXT_VERSION_MINOR, 3);
	glfwWindowHint(GLFW_OPENGL_PROFILE, GLFW_OPENGL_CORE_PROFILE);
	
	GLFWwindow* window = glfwCreateWindow(800, 600, "GLFW test window", nullptr, nullptr);
	
	if (!window) {
		glfwTerminate();
		exit(EXIT_FAILURE);
	}
	
	glfwSetWindowCloseCallback(window, window_close_callback);
	glfwSetKeyCallback(window, key_callback);
	
	glfwMakeContextCurrent(window);
	glfwSwapInterval(1);
	
	while (!glfwWindowShouldClose(window)) {
//		int width, height;
//		glfwGetFramebufferSize(window, &width, &height);
//		glViewport(0, 0, width, height);
		
		double time = glfwGetTime();
		std::cout << time << std::endl;
		
		glfwSwapBuffers(window);
		glfwPollEvents();
	}
	
	glfwDestroyWindow(window);
	
	glfwTerminate();
	exit(EXIT_SUCCESS);
}
