#include <iostream>
#include <vector>

using namespace std;

int findPositionalDistance(const vector<int>& numbers, int num1, int num2) {
    int position1 = -1; 
    int position2 = -1;

    for (size_t i = 0; i < numbers.size(); ++i) {
        if (numbers[i] == num1) {
            position1 = i; 
        }
        if (numbers[i] == num2) {
            position2 = i; 
        }
    }

    
    if (position1 != -1 && position2 != -1) {
        return abs(position2 - position1); 
    } else {
        return -1;
    }
}

int main() {
    vector<int> numbers = {3, 8, 12, 17, 5, 20, 10};
    int num1 = 20;
    int num2 = 8;

    int distance = findPositionalDistance(numbers, num1, num2);

    if (distance != -1) {
        cout << "Positional distance between " << num1 << " and " << num2 << " is: " << distance << endl;
    } else {
        cout << "One or both numbers were not found in the vector." << endl;
    }

    vector<int> movedNumbers = move(numbers);

    distance = findPositionalDistance(movedNumbers, num1, num2);

    if (distance != -1) {
        cout << "Positional distance between " << num1 << " and " << num2 << " is: " << distance << endl;
    } else {
        cout << "One or both numbers were not found in the vector." << endl;
    }

    return 0;
}
