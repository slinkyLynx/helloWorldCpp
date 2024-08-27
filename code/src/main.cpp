#include <ball.hpp>

#include <iostream>

#include <glm/glm.hpp>

int main() {
	std::cout << "Hello, world!" << std::endl;
	glm::vec3 pos{1.0f, 2.1f, 3.4f};
	Ball b{pos};
	std::cout << "b Position: (" << b.pos().x << ", " << b.pos().y << ", " << b.pos().z << ")" << std::endl;
	std::cout << "b Magnitude: " << b.distanceFromPoint(glm::vec3{}) << std::endl;
	Ball c{b};
	c.moveToUnitVec();
	std::cout << "c Position: (" << c.pos().x << ", " << c.pos().y << ", " << c.pos().z << ")" << std::endl;
	std::cout << "c Magnitude: " << c.distanceFromPoint(glm::vec3{}) << std::endl;
	std::cout << "Distance between b and c: " << b.distanceFromPoint(c.pos()) << std::endl;
	return 0;
}
