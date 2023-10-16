#include <string>
#include <iostream>

int main()
{
    std::basic_string<char> basic = "Hello World!";

    std::cout << "STL container basic_string result: ";

    /* Valid iterator referencing elements in the basic_string */
    for(std::basic_string<char>::iterator i = basic.begin(); i != basic.end(); i++)
    {
        std::cout << *i;
    }
    return 0;
}