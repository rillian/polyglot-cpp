#include <iostream>
#include <cstdint>
#include "Vector2d.h"
#include "Shape.h"
#include "Circle.h"
#include "Rectangle.h"

int main() {
  auto a = 1;
  auto& b = a;
  b = 2;

  std::cout << a << std::endl;


  auto u = poly::Vector2d{2,3,4};
  auto v = poly::Vector2d::buildWithAngleAndMagnitude(M_PI, 1);
  auto w = 3 * (u + v) * 8;

  std::cout << w.magnitudeSquared() << std::endl;

  auto circle = poly::Circle(poly::Vector2d{100,100}, 75);
  auto rect = poly::Rectangle(poly::Vector2d{50,50}, poly::Vector2d{100,100});

  return 0;
}
