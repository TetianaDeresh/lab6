#include <iostream>
#include <iomanip>
#include <cstdint>

uint8_t gfMultiply(uint8_t a, uint8_t b) {
    uint8_t result = 0;

    while (b) {
        if (b & 1) {
            result ^= a;
        }

        if (a & 0x80) {
            a = (a << 1) ^ 0x1B;
        } else {
            a <<= 1;
        }

        b >>= 1;
    }

    return result;
}

int main() {
    uint8_t byte1 = 0x57; 
    uint8_t byte2 = 0x83; 

    uint8_t result = gfMultiply(byte1, byte2);

    std::cout << std::hex << std::uppercase << "Result of "
              << std::setw(2) << std::setfill('0') << static_cast<int>(byte1)
              << " * "
              << std::setw(2) << std::setfill('0') << static_cast<int>(byte2)
              << " = "
              << std::setw(2) << std::setfill('0') << static_cast<int>(result)
              << std::endl;

    return 0;
}
