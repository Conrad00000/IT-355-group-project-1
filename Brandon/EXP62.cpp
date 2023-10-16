#include <iostream>
#include <cstring>

struct S {
    int value;
};

int main() {
    S obj1 = {42};
    S obj2 = {42};

    if (std::memcmp(&obj1, &obj2, sizeof(S)) == 0) {
        std::cout << "Objects are equal" << std::endl;
    } else {
        std::cout << "Objects are not equal" << std::endl;
    }

    return 0;
}
