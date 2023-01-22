#include <iostream>
#include <bitset>

// return an integer that has the same weight as the input(same # of 1)
// and it as small as possible
// eg. input = 1011, output = 1101
// idea: find the rightmost 2 consective bits that are diff
//       and flip them
const int kNumUnsignBits = 64;

long SameWeight(long x) {
    for(int i = 0; i < kNumUnsignBits - 1; i++) {
        // two consective bits differ
        if(((x >> i) & 1) ^ (x >> (i+1) & 1)) {
            // swap bit i and i + 1
            long bit_mask = (1L << i) | (1L << (i + 1));
            x ^= bit_mask;
            break;
        }
    }
    return x;
}

int main() {
    int x{42};
    std::cout << x << ": " << std::bitset<sizeof(x) * 8>(x) << std::endl;
    std::cout << "same weight: " << std::bitset<sizeof(x) * 8>(SameWeight(x)) << std::endl;
}