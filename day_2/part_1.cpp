#include <array>
#include <iostream>
#include <stdint.h>
#include <set>
#include <algorithm>

constexpr std::array<std::int64_t, 12> powersTen {1, 10, 100, 1000, 10000, 100000, 1000000, 10000000, 100000000, 1000000000, 10000000000, 100000000000};

bool isValid(int64_t number) {
  int numberOfDigits {0};
  for (std::int64_t power: powersTen) {
    if (number < power)
      break;
    numberOfDigits++;
  }

  if (numberOfDigits % 2 == 1) {
    return true;
  }
  else {
    std::int64_t divThing {powersTen[numberOfDigits / 2] + 1};
    bool valid {number % divThing != 0};
    return valid;
  }
}

// Too Low
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