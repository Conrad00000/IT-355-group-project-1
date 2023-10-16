#include <iostream>
#include <string>
#include <type_traits>

using namespace std; 

template <typename... Args>
int sum(Args... args) {
    return (static_cast<int>(args) + ...);
}

string encryptString(const string& input, int shift) {
    string encrypted = input;

    for (size_t i = 0; i < encrypted.size(); ++i) {
        char& character = encrypted[i];

        if (isalpha(character)) {
            char base = islower(character) ? 'a' : 'A';
            character = static_cast<char>((character - base + shift) % 26 + base);
        }
    }

    return encrypted;
}

struct Student {
    string name;
    string year;
};

int main() {
    //DCL50
    int result1 = sum(10, 20, 30);
    int result2 = sum(1, 2, 3, 4);
    cout << "Result 1: " << result1 << endl;
    cout << "Result 2: " << result2 << endl;

    //STR50
    string startString = "This is it";
    cout << "Start String: This is it" << endl;
    string encrypted = encryptString("This is it",5);
    cout << "End String: " << encrypted << endl;

    //MEM50
    Student *stu1 = new Student;

    stu1->name = "Connor";
    stu1->year = "Senior";

    cout << "Student Name: " << stu1->name << endl;
    cout << "Student Year: " << stu1->year << endl;

    cout << endl;


    delete stu1; //stu1 does not get accessed after deletion. 

    return 0;
}

