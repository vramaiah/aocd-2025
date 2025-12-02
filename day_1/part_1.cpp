#include <iostream>

int main() {
    int pos { 50 };
    int numZeros { 0 };
    while(true) {
        char dir {};
        int rotation { 0 };
        std::cin >> dir;
        std::cin >> rotation;
        if (dir ==  'R')
            pos += rotation;
        if (dir == 'L')
            pos -= rotation;
        if (dir == 'Q') {
            std::cout << numZeros;
            return 0;
        }
        if (pos < 0)
            pos = 100 + pos;
        pos = pos % 100;
        if (pos == 0)
            numZeros += 1;
    }
}