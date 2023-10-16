#include <memory>

class A
{
    std::shared_ptr<class Body> ptr; //capable of referring to an incomplete type
    public:
        A(){};
        ~A(){};
};

int main()
{
    A myobj;
    return 0;

}