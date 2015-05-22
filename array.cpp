#include <array>
#include <iostream>

int main() {
  auto a = std::array<int,4>{1,2,3,4};
  for (auto& e : a) {
    std::cout << e << std::endl;
  }
}
