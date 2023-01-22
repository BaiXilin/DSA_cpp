#include <iostream>

unsigned int Add(unsigned a, unsigned b) {
    unsigned sum = 0, carryin = 0, k = 1, temp_a = a, temp_b = b;
    while(temp_a || temp_b) {
        unsigned ak = a & k, bk = b & k;
        unsigned carryout = (ak & bk) | (ak & carryin) | (bk & carryin);
        sum |= (ak ^ bk ^ carryin);
        carryin = carryout << 1, k <<= 1, temp_a >>= 1, temp_b >>= 1;
    }
    return sum | carryin;
}

unsigned int Multiply(unsigned x, unsigned y) {
    unsigned sum = 0;

    while(x) {
        if(x & 1) {
            sum = Add(sum, y);
        }
        x >>= 1, y <<= 1;
    }
    return sum;
}

int main() {
    unsigned x = 42, y = 6;
    std::cout << Multiply(42, 6) << std::endl;
}