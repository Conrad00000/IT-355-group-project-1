#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
#include <memory>
#include <fstream>

//DCL50: 
//DCL58: Standard name spaces are not changed
using namespace std;
template<typename T, typename... Args>
void DisplayAllCarsInfo(const T& car, Args... args) {
    std::cout << "Welcome to the Car Garage!" << std::endl;
    std::cout << "Here are the cars parked in the garage:" << std::endl;

    car->displayCar();  // Display the first car

    // Display the rest of the cars
    (args->displayCar(), ...);
}

auto g() //EXP61 - Lambda captures secureCode by copy instead of by reference. Therefore, secureCode variable has same lifetime as lambda function.
{
    string secureCode = "The lamborghini is my favorite car...";

    return [=] () mutable
    {
        return secureCode; 
    };
}
//DCL60: Car class is only defined once in the program, so is lambda function g
class Car
{
    private:
        std::shared_ptr<class Body> ptr; //EXP57 - capable of referring to an incomplete type/class
        string color;
        string make;
        string model;

    public:
        Car(string make, string model, string color) 
        {
            this->make = make;
            this->model = model;
            this->color = color;
        }
        void displayCar()
        {
            std::basic_string<char> color = this->color;
            std::basic_string<char> model = this->model;
            std::basic_string<char> make = this->make;

            std::cout << "The information you provided: " << endl;

            /* STR52 - Valid iterator referencing elements in the basic_string */
             for(std::basic_string<char>::iterator i = make.begin(); i != make.end(); i++) 
            {
                std::cout << *i;
            }
            cout << endl;
             for(std::basic_string<char>::iterator i = model.begin(); i != model.end(); i++) 
            {
                std::cout << *i;
            }
            cout << endl;
            for(std::basic_string<char>::iterator i = color.begin(); i != color.end(); i++) 
            {
                std::cout << *i;
            }
            cout<<endl;
        }

        virtual ~Car() = default; // OOP52 - Explicitly defined destructor for polymorphic object to ensure defined behavior

};



int main()
{
    string make;
    string model;
    string color;
    string car1;
    string car2;
    string car3;

    string fileName = "cars.txt";
    fstream file(fileName);
    string inputString;

    file << "The cars output stream...";
    /* FIO50 - intervening position call removing undefined behavior */
    file.seekg(0, ios::beg);
    file >> inputString;

    vector<string> srcVector = {};
    vector<string> destVector(4);

    //STR50
    cout << "\nWelcome to the car shop\n" << endl;
    cout << "---------------------------" << endl;
    cout << "Enter make: ";
    cin >> make;
    cout << "Enter model: ";
    cin >> model;
    cout << "Enter color: ";
    cin >> color;

    Car *car = new Car(make, model, color);
    car->displayCar();
    car = nullptr;
    delete car;
    //MEM51
    //MEM52: Memory is dynamically allocated with 'new Car' and then deallocated with 'delete car'
    //EXP54 -After deleting an object it should no longer be accessed otherwise undefined behavior
    // DisplayAllCarsInfo(car);


    cout << "Enter your 3 favorite cars" << endl;
    cout << "Car 1:";
    cin >> car1;
    cout << "Car 2:";
    cin >> car2;
    cout << "Car 3:";
    cin >> car3;

    srcVector.push_back(car1);
    srcVector.push_back(car2);
    srcVector.push_back(car3);
    
    copy(srcVector.begin(), srcVector.end(), destVector.begin()); //CTR52 - Destination vector holds enough space so no buffer overflows
    cout << "The cars:" << endl;
    /* CTR55 - min makes sure we won't step out of bounds of the container */
    for(auto i = destVector.begin(), e = i + min(sizeof(srcVector), destVector.size()); i != e; i++) 
    {
        cout << *i << " ";
    }
    
    cout << endl;
    cout << g()() << endl;
    
                    
    return 0;
}



