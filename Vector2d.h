#pragma once

#include <initializer_list>
#include <cmath>

namespace poly {

class Vector2d {
  public:
    using type = double; // type alias, typedef that works with templates.

  public:
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

    auto magnitudeSquared() {
      return _x*_x + _y*_y;
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

    Vector2d& operator*=(const type rhs) {
      _x *= rhs;
      _y *= rhs;
      return *this;
    }

  private:
    type _x = 0;
    type _y = 0;
};

// Free function for binary operators.
inline
Vector2d operator+(const Vector2d& lhs, const Vector2d& rhs) {
  auto result = lhs;
  return result += rhs;
}

inline
Vector2d operator-(const Vector2d& lhs, const Vector2d& rhs) {
  auto result = lhs;
  return result -= rhs;
}

inline
Vector2d operator*(const Vector2d& lhs, const Vector2d::type rhs) {
  auto result = lhs;
  return result *= rhs;
}

inline
Vector2d operator*(const Vector2d::type lhs, const Vector2d& rhs) {
  auto result = rhs;
  return result *= lhs;
}

} // namespace poly
