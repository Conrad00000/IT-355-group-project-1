#include <iostream>



auto g()
{
    int num = 10;
    /* 
        Lambda captures num by copy instead of by reference. Therefore, num has same
        lifetime as lambda function 
     */
    return [=] () mutable
    {
        num = 20;
        return num;
    };
}

int main()
{

    int result = g()();

    std::cout << "Result after calling lambda function: " << result << std::endl;

    return 0;
}