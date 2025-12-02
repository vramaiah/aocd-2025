#include <iostream>
#include <cmath>

int main() {
  int pos { 50 };
  int numZeros { 0 };
  while(true) {
    char dir {};
    int rotation { 0 };
    int amountToRotate {};
    int numHundreds {};
    std::cin >> dir;
    std::cin >> rotation;
    if (dir ==  'R') {
      std::cout << "(R) rotation: " << rotation;
      amountToRotate = rotation;
      numHundreds = amountToRotate / 100;
      numZeros += numHundreds;
      amountToRotate -= numHundreds * 100;
      std::cout << ", numHundreds: " << numHundreds;
            pos += amountToRotate;
      if (pos >= 100) {
          std::cout << ", zero encountered";
          numZeros += 1;
          pos -= 100;
      }

      std::cout << ", pos: " << pos;
      std::cout << std::endl;
    }
    if (dir == 'L') {
        int oldpos {pos};
      std::cout << "(L) rotation: " << rotation;
      amountToRotate = rotation;
      numHundreds = amountToRotate / 100;
      numZeros += numHundreds;
      amountToRotate -= numHundreds * 100;
      std::cout << ", numHundreds " << numHundreds;
      pos -= amountToRotate;
      if (pos <= 0 && (oldpos != 0)) {
          std::cout << ", zero encountered";
        numZeros += 1;
      }

      if (pos < 0)
        pos = 100 + pos;
      std::cout << ", pos: " << pos;
      std::cout << std::endl;
    }
    if (dir == 'Q') {
      std::cout << numZeros;
      return 0;
    }
  }
}