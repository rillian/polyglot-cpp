#include "Rectangle.h"

namespace poly {

Rectangle::Rectangle(const Vector2d& top_left, const Vector2d& size) {
  _top_left = top_left;
  _size = size;
}

void
Rectangle::draw() {
  // TODO
}

bool
Rectangle::hitTest(const Vector2d& point) const {
  return
    point.x() >= _top_left.x() &&
    point.y() >= _top_left.y() &&
    point.x() < _top_left.x() + _size.x() &&
    point.y() < _top_left.y() + _size.y();
}

} // namespace poly
