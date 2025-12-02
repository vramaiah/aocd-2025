#include <array>
#include <iostream>
#include <stdint.h>
#include <set>
#include <algorithm>
#include <regex>

// Invalid numbers regex
std::regex pattern {"^(\\d+)\\1+$"};

bool isValid(int64_t number) {
  std::string numberString {std::to_string(number)};
  if (std::regex_match(numberString, pattern)) {
    std::cout << number << std::endl;
    return false;
  }
  else
    return true;
}

// Really slow but this is c++ so who cares
int main() {
  std::set<std::int64_t> invalidNumbers {};
  while (true) {
    std::int64_t start {};
    std::int64_t end {};
    char sep {};
    std::cin >> start;
    std::cin >> sep;
    std::cin >> end;
    std::cin >> sep;

    for (int64_t i {start}; i <= end; ++i) {
      if (!isValid(i))
        invalidNumbers.insert(i);
    }
    if (sep == 'q') {
      int64_t sum {0};
      for (std::int64_t elem: invalidNumbers)
        sum += elem;
      std::cout << sum << std::endl;
      return 0;
    }
  }
}