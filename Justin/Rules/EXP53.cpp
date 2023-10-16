#include <iostream>

int main()
{

    /* Compliant code */

    int a = 0;
    std::cout << "a: " << a << std::endl;

    int* i = new int(); //initializes i to be 0
    std::cout << "i: " << *i << std::endl;

    int *j = new int{}; //initilizes j to be 0
    std::cout << "j: " << *j << std::endl;
    
    int *k = new int(12);
    int *l = new int{12};

    std::cout << "k: " << *k << std::endl;
    std::cout << "l: " << *l << std::endl;

    return 0;
}