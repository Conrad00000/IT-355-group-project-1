#include <memory>

struct Base
{
    /* Explicitly defined destructor for polymorphic object to ensure defined behavior */
    virtual ~Base() = default;
};

struct Derived : Base{};

int main()
{
    Base *obj = new Derived();
    delete obj;

    return 0;
}