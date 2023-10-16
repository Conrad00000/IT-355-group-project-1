#include <random>
#include <iostream>

int main() {
    std::random_device rd;
    std::mt19937 engine(rd()); // Properly seeded with a random value

    for (int i = 0; i < 10; ++i) {
        std::cout << engine() << ", "; // Generate random numbers
    }

    return 0;
}
