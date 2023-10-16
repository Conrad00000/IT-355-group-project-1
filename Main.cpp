#include <iostream>
#include <vector>
#include <string>

using namespace std;

template <typename... Args>
int sum(Args... args) {
    return (static_cast<int>(args) + ...);
}



int main()
{
    vector<string> msg {"Hello", "C++", "World", "from", "VS Code", "and the C++ extension!"};

    for (const string& word : msg)
    {
        cout << word << " ";
    }
    cout << endl;
}



