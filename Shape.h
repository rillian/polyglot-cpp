#pragma once

namespace poly {

// abstract class
class Shape {
  virtual ~Shape() = default;
  virtual void draw() = 0;
  virtual bool hitTest(const Vector2d& point) const = 0;
};

} // namespace poly
