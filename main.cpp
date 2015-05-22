#include <iostream>
#include <cstdint>
#include "Vector2d.h"
#include "Shape.h"
#include "Circle.h"

namespace poly {

// Vector "unit tests"
auto v = Vector2d{2,3,4};
auto u = Vector2d::buildWithAngleAndMagnitude(M_PI, 1);
void f() {
    auto w = 3 * (u + v) * 8;
}

} // namespace poly

int main() {
  auto a = 1;
  auto& b = a;
  b = 2;

  std::cout << a << std::endl;
  return 0;
}
