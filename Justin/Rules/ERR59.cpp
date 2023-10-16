
#include <stdexcept>
#include <iostream>


#include "ERR59.h" //exception across modules
int main()
{
    int result = func(); //returning a value instead of an exception and then handling the error
    if(result != 5)
    {
        throw std::runtime_error("Exception handling!");
    }
    return 0;
}