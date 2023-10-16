#include <iostream>
#include <cstdlib>
#include <new>

struct alignas(32) myStruct
{
    int num = 2;
    
};

int main()
{
    /* We use alignas with the new operator to meet the requirements for memory */
    alignas(32) char buffer[sizeof(myStruct)];

    myStruct* obj = new(buffer) myStruct;

    std::cout << "Data in struct with size " << sizeof(myStruct) << ": " <<  obj->num << std::endl;

    return 0;
}