#include <iostream>
#include <stdexcept>

int main(int argc, const char* argv[]) {
  int* numbers = nullptr;
  try {
    numbers = new int[1'000'000'000'000'000];
    std::cout << "Success" << std::endl;
  } catch (std::bad_alloc& e) {
    std::cerr << "Failure: " << e.what() << std::endl;
  }
  return numbers == nullptr;
}
