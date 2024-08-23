#include <glm/glm.hpp>

class Ball {
public:
	Ball();
	Ball(const float x, const float y, const float z);
	Ball(const glm::vec3& pos);
	Ball(const Ball& ball);
	Ball& operator=(const Ball& rhs);

	glm::vec3 pos() const;
	
	void moveToUnitVec();
	float distanceFromPoint(const glm::vec3& point) const;

private:
	glm::vec3 mPos;
};
