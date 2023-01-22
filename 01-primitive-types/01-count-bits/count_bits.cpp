#include <iostream>
#include <bitset>

short CountBits(unsigned int n) {
    short num_bits = 0;
    while(n) {
        num_bits += n & 1;
        n >>= 1;
    }
    return num_bits;
}

int main() {
    int n{56};
    short num_bits = CountBits(56);
    std::cout << n << "'s binary form is " << std::bitset<sizeof(n) * 8>(n) << std::endl;
    std::cout << n << " has " << num_bits << " bits" << std::endl;
    
    return 0;
}