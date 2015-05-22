#include <iostream>

int main() {
  auto hello_lambda = [](auto who) {
    std::cout << "Hello, " << who << "!" << std::endl;
  };
  hello_lambda("world");
  return 0;
}
