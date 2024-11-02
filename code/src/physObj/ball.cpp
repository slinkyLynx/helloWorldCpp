#include "ball.hpp"

#include <iostream>

Ball::Ball() : mPos{0.0f, 0.0f, 0.0f} {}

Ball::Ball(const float xPos, const float yPos, const float zPos)
    : mPos{xPos, yPos, zPos} {}

Ball::Ball(const glm::vec3 &pos) : mPos{pos} {}

Ball::Ball(const Ball &ball) { this->mPos = ball.pos(); }

Ball &Ball::operator=(const Ball &rhs) {
  if (this == &rhs) {
    std::cout << "These two balls are the same!" << std::endl;
    return *this;
  }
  this->mPos = rhs.pos();
  return *this;
}

glm::vec3 Ball::pos() const { return mPos; }

void Ball::moveToUnitVec() { mPos = glm::normalize(mPos); }

float Ball::distanceFromPoint(const glm::vec3 &point) const {
  glm::vec3 temp(mPos.x - point.x, mPos.y - point.y, mPos.z - point.z);
  return glm::length(temp);
}
