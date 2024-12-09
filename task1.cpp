#include <iostream>
#include <iomanip>

// Function to multiply a byte by 0x02 in GF(2^8)
uint8_t mul02(uint8_t byte) {
    uint16_t result = byte << 1; // Shift left by 1 bit
    if (byte & 0x80) {           // Check if the most significant bit is set
        result ^= 0x1B;          // XOR with the primitive polynomial
    }
    return static_cast<uint8_t>(result & 0xFF); // Return 8-bit result
}

// Function to multiply a byte by 0x03 in GF(2^8)
uint8_t mul03(uint8_t byte) {
    return mul02(byte) ^ byte; // Multiply by 0x02 and XOR with the original byte
}

int main() {
    uint8_t byte1 = 0x45;
    uint8_t result1 = mul02(byte1);
    std::cout << std::hex << std::uppercase << "D4 * 02 = " 
              << std::setw(2) << std::setfill('0') << static_cast<int>(result1) << std::endl;

    uint8_t byte2 = 0xBF;
    uint8_t result2 = mul03(byte2);
    std::cout << std::hex << std::uppercase << "BF * 03 = " 
              << std::setw(2) << std::setfill('0') << static_cast<int>(result2) << std::endl;

    return 0;
}
