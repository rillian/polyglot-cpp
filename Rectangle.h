#pragma once

#include "Shape.h"

namespace poly {

class Rectangle : public Shape {
  public:
    Rectangle() = default;
    Rectangle(Vector2d& top_left, Vector2d& size);
    void draw() override;
    bool hitTest(const Vector2d& point) const override;
    ~Rectangle() = default;

  private:
    Vector2d _top_left;
    Vector2d _size;
};

} // namespace poly
