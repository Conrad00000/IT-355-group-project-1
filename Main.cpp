#include <iostream>
#include <vector>
#include <string>

using namespace std;

template <typename... Args>
int sum(Args... args) {
    return (static_cast<int>(args) + ...);
}

class A
{
    public:

        A(){ cout << "After object deletion it should not be accessed otherwise it is undefined behavior\n";}
};

int main()
{
    vector<string> msg {"Hello", "C++", "World", "from", "VS Code", "and the C++ extension!"};

    for (const string& word : msg)
    {
        cout << word << " ";
    }
    cout << endl;

    
    A myObj;
    delete &myObj; //EXP54

    int *i = new int(5);
    int j = 6;

    cout << "Variables should be initialized before reading. i: " << i << "j: " << j << endl;

    return 0;
}



