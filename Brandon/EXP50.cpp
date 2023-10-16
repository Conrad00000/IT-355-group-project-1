#include <iostream>

int main() {
    int i = 5;
    int result = i++ + i; // The order of evaluation is unspecified
    std::cout << "Result: " << result << std::endl;

    return 0;
}
