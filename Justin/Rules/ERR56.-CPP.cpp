#include <cstring>

class myClass
{
    private:
        int *array;
    public: 
        ~myClass(){
            delete[] array;
        }

    myClass(const myClass& safety);

    myClass& operator=(const myClass &rhs) //provides the strong exception safety
    {
        return *this;
    }

};

int main()
{
    

    return 0;
}