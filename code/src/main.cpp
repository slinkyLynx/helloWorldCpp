/*#include <ball.hpp>

#include <iostream>

#include <GLFW/glfw3.h>

#include <glm/glm.hpp>

void error_callback(int error, const char* description) {
        std::cerr << "Error: " << error << '\n' << description << std::endl;
}

void window_close_callback(GLFWwindow*) {
        std::cout << "Closing window!" << std::endl;
}

void key_callback(GLFWwindow* window, int key, int scancode, int action, int
mods) { std::cout << "key = " << key
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
        glfwWindowHint(GLFW_CLIENT_API, GLFW_NO_API);
//	glfwWindowHint(GLFW_OPENGL_PROFILE, GLFW_OPENGL_CORE_PROFILE);

        GLFWwindow* window = glfwCreateWindow(800, 600, "Vulkan test window",
nullptr, nullptr);

        if (!window) {
                glfwTerminate();
                exit(EXIT_FAILURE);
        }

        glfwSetWindowCloseCallback(window, window_close_callback);
        glfwSetKeyCallback(window, key_callback);

//	glfwMakeContextCurrent(window);
//	glfwSwapInterval(1);

        while (!glfwWindowShouldClose(window)) {
//		int width, height;
//		glfwGetFramebufferSize(window, &width, &height);
//		glViewport(0, 0, width, height);

                double time = glfwGetTime();
                std::cout << time << std::endl;

//		glfwSwapBuffers(window);
                glfwPollEvents();
        }

        glfwDestroyWindow(window);

        glfwTerminate();
        exit(EXIT_SUCCESS);
}*/

#define GLFW_INCLUDE_VULKAN
#include <GLFW/glfw3.h>

#define GLM_FORCE_RADIANS
#define GLM_FORCE_DEPTH_ZERO_TO_ONE
#include <glm/mat4x4.hpp>
#include <glm/vec4.hpp>

#include <vulkan/vulkan.hpp>

#include <iostream>

int main() {
  glfwInit();

  glfwWindowHint(GLFW_CLIENT_API, GLFW_NO_API);
  GLFWwindow *window =
      glfwCreateWindow(800, 600, "Vulkan window", nullptr, nullptr);

  uint32_t extensionCount = 0;
  vkEnumerateInstanceExtensionProperties(nullptr, &extensionCount, nullptr);

  std::cout << extensionCount << " extensions supported\n";

  glm::mat4 matrix{1.0f};
  glm::vec4 vec{0.0f, 0.0f, 0.0f, 1.0f};
  auto test = matrix * vec;

  std::cout << "(" << test.x << ", " << test.y << ", " << test.z << ", "
            << test.w << ")" << std::endl;

  while (!glfwWindowShouldClose(window)) {
    glfwPollEvents();
  }

  glfwDestroyWindow(window);

  glfwTerminate();

  return 0;
}
