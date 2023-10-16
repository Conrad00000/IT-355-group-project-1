#include <iostream>
#include <string>
#include <vector>

using namespace std;

class Student {
private:
    string name;
    const int studentID; 
    double* classGPAs;    
    size_t numClasses;    

public:
    // Constructor
    Student(const string& name, int studentID)
        : name(name), studentID(studentID), classGPAs(nullptr), numClasses(0) {}

    // Getters
    string getName() const {
        return name;
    }

    int getStudentID() const {
        return studentID;
    }

    const double* getClassGPAs() const {
        return classGPAs;
    }

    size_t getNumClasses() const {
        return numClasses;
    }

    // Setters
    void setName(const string& newName) {
        name = newName;
    }

    void addClassGPA(double gpa) {
        double* newClassGPAs = new double[numClasses + 1];
        
        for (size_t i = 0; i < numClasses; ++i) {
            newClassGPAs[i] = classGPAs[i];
        }

        newClassGPAs[numClasses] = gpa;
        ++numClasses;

        delete[] classGPAs;

        classGPAs = newClassGPAs;
    }

    void sortGPAs(){
        for (int i = 0; i < numClasses - 1; i++) {
            for (int j = 0; j < numClasses - i - 1; j++) {
                if (classGPAs[j] > classGPAs[j + 1]) {
                    // Swap arr[j] and arr[j + 1]
                    double temp = classGPAs[j];
                    classGPAs[j] = classGPAs[j + 1];
                    classGPAs[j + 1] = temp;
                }
            }
        }
    }

    void printGPAs(){
        cout << "all GPAs: ";
        for(int i = 0; i< numClasses; i++){
            cout << classGPAs[i] << " ";
        }
        cout << endl;
    }

    double calculateGPA() const {
        if (numClasses == 0) {
            return 0.0;
        }

        double totalGPA = 0.0;
        for (size_t i = 0; i < numClasses; ++i) {
            totalGPA += classGPAs[i];
        }
        return totalGPA / numClasses;
    }

    // Destructor
    ~Student() {
        try {
            delete[] classGPAs;
            cout << "Destructor called for student with ID " << studentID << endl;
        } catch (const exception& e) {
            cerr << "Exception in destructor: " << e.what() << endl;
        }
    }
};

int main() {
    // Create a Student object with a constant student ID
    Student student("John Doe", 12345);

    // Add GPAs for classes
    student.addClassGPA(3.7);
    student.addClassGPA(4.0);
    student.addClassGPA(3.5);

    student.printGPAs();
    student.sortGPAs();
    student.printGPAs();

    // Calculate and display the overall GPA
    double overallGPA = student.calculateGPA();
    cout << "Student: " << student.getName() << " With ID: " << student.getStudentID() << endl;
    cout << "Overall GPA: " << overallGPA << endl;

    return 0;
}
