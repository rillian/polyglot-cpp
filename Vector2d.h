#pragma once

#include <initializer_list>
#include <cmath>

namespace poly {

class Vector2d {
  public:
    using type = double; // type alias, typedef that works with templates.

    // ctors
    Vector2d() = default; // explicit default for consistency.
    Vector2d(type x, type y) : _x(x), _y(y) {}
    Vector2d(std::initializer_list<type> list) {
      auto iter = list.begin();
      if (iter != list.end()) {
        _x = *iter;
      }
      ++iter;
      if (iter != list.end()) {
        _y = *iter;
      }
    }

#if 0
    Vector2d(const Vector2d& v) = delete; // copy ctor
    Vector2d(const Vector2d&& v) = default; // move ctor

    ~Vector2d() { // dtor
      std::cout << "vector destroyed\n";
    }

    Vector2d& operator=(const Vector2d& v) = default;

#endif
    static Vector2d buildWithAngleAndMagnitude(type angle, type magnitude) {
      return Vector2d{magnitude * cos(angle), magnitude * std::sin(angle)};
    }

    // accessors

    // operators

  private:
    type _x = 0;
    type _y = 0;
};

auto v = Vector2d{2,3,4};
auto u = Vector2d::buildWithAngleAndMagnitude(M_PI, 1);
void f() {
  u = v;
}

} // namespace poly
