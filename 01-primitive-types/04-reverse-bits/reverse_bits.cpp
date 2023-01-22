#include <iostream>
#include <bitset>

long SwapBits(long x, int i, int j) {
    // test if two bits to swapped are the same
    if(((x>>i) & 1) ^ ((x>>j) & 1)) {
        // they are different
        // flip the bit on index i and j
        unsigned long bit_mask = (1L << i) | (1L << j);
        return (x ^ bit_mask);
    } else {
        // they are the same
        // do nothing and return the original
        return x;
    }
}

long ReverseBits(long x) {
    long result = x;
    for(int i = 0; i <= (sizeof(x)*8)/2; i++) {
        result = SwapBits(result, i, sizeof(x)*8 - i);
    }

    return result;
}

int main() {
    long x{42};
    std::cout << x << ": " << std::bitset<sizeof(x) * 8>(x) << std::endl;
    std::cout << "After reverse: " << std::bitset<sizeof(x) * 8>(ReverseBits(x)) << std::endl;
}