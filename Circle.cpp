#include "Circle.h"

namespace poly {

Circle::Circle(Vector2d& center, Vector2d::type radius) {
  _center = center;
  _radius = radius;
}

void
Circle::draw() {
  // TODO
}

bool
Circle::hitTest(const Vector2d& point) const {
  auto diff = _center - point;
  return diff.magnitudeSquared() < _radius;
}

} // namespace poly
