#include <iostream>

class A
{
    private:
        int num = 5;
    public:
        void print() { std::cout << num << std::endl; }
        A(){};
};

int main()
{
    A myObj;
    
    myObj.print();

    delete &myObj;

    /*
        Executing the following line will result in undefined behavior since we are trying to
        make use of a deleted object
    */
    //myObj.print();

    return 0;
}