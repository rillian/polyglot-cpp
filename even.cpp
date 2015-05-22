#include <algorithm>
#include <iostream>
#include <iterator>
#include <vector>

auto generate_even(int n) {
  auto values = std::vector<int>{};
  auto x = 0;
  auto gen = [&x]() { return x += 2; };
  std::generate_n(std::inserter(values, std::begin(values)), n, gen);
  return values;
}

auto isEven(int v) { return v % 2 == 0; }

auto checkEven(const std::vector<int>& vector) {
  return std::all_of(std::begin(vector), std::end(vector), isEven);
}

int main(int argc, const char* argv[]) {
  // something with std::copy and std::ofstream_iterator(cout,...)
  return 0;
}

