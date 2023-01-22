#include <iostream>
#include <bitset>

short parity(unsigned long x) {
    short result;
    while(x) {
        result ^= (x & 1);
        x >>= 1;
    }
    return result;
}

int main() {
    int x{43};
    short result = parity(x);

    std::cout << x << ": " << std::bitset<sizeof(x) * 8>(x) << std::endl;
    std::cout << result << std::endl;
    if(result) {
        std::cout << x << " has an odd parity" << std::endl; 
    } else {
        std::cout << x << " has an even parity" << std::endl;
    }
}