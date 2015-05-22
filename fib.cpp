#include <array>
#include <iostream>
#include <cassert>

// C++14 lets us use multiple return statements in a constexpr.
inline constexpr auto fib(int n) noexcept {
  if (n == 0 || n == 1) {
    return 1;
  }
  return fib(n-1) + fib(n-2);
}

int main() {
  std::array<int, fib(4)> a;
  std::cout << "fib(4) is " << a.size() << std::endl;
  assert(a.size() == 5);
  return 0;
}
