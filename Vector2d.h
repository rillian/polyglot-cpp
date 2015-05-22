#pragma once

#include <initializer_list>

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
    // accessors

    // operators

  private:
    type _x = 0;
    type _y = 0;
};

auto v = Vector2d{2,3,4};

} // namespace poly
