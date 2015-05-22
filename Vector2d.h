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

    auto x() const {
      return _x;
    }

    auto y() const {
      return _y;
    }

    auto setX(type x) {
      _x = x;
    }

    auto setY(type y) {
      _y = y;
    }

    // operators
    Vector2d& operator+=(const Vector2d& rhs) {
      _x += rhs._x;
      _y += rhs._y;
      return *this;
    }

    Vector2d& operator-=(const Vector2d& rhs) {
      _x -= rhs._x;
      _y -= rhs._y;
      return *this;
    }

  private:
    type _x = 0;
    type _y = 0;
};

// Free function for binary operators.
Vector2d operator+(const Vector2d& lhs, const Vector2d& rhs) {
  auto result = lhs;
  return result += rhs;
}

Vector2d operator-(const Vector2d& lhs, const Vector2d& rhs) {
  auto result = lhs;
  return result -= rhs;
}

Vector2d operator*(const Vector2d& lhs, const Vector2d::type rhs) {
  auto result = lhs;
  result.setX(lhs.x() * rhs);
  result.setY(lhs.y() * rhs);
  return result;
}

Vector2d operator*(const Vector2d::type lhs, const Vector2d& rhs) {
  auto result = rhs;
  result.setX(lhs * rhs.x());
  result.setY(lhs * rhs.y());
  return result;
}

auto v = Vector2d{2,3,4};
auto u = Vector2d::buildWithAngleAndMagnitude(M_PI, 1);
void f() {
  auto w = 3 * (u + v) * 8;
}

} // namespace poly
