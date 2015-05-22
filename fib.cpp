// C++14 lets us use multiple return statements in a constexpr.
inline constexpr auto fib(int n) noexcept {
  if (n == 0 || n == 1) {
    return 1;
  }
  return fib(n-1) + fin(n-2);
}

std::array<int, fib(4)> a;
