#pragma once

#include "Shape.h"

namespace poly {

class Circle : public Shape {
  public:
    Circle() = default;
    Circle(Vector2d& center, Vector2d::type r);
    void draw() override;
    bool hitTest(const Vector2d& point) const override;
    ~Circle() = default;

  private:
    Vector2d _center;
    Vector2d::type _radius = 0;
};

} // namespace poly
