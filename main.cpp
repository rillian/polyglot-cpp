#include <iostream>
#include <cstdint>

int main() {
  auto a = 1;
  auto& b = a;
  b = 2;

  std::cout << a << std::endl;
  return 0;
}