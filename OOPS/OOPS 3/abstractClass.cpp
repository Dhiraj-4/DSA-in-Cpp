#include<iostream>
using namespace std;

class Vehicle {
    // Abstract class is a class which only has pure virtual functions

    // pure virtual function = Declaration in Base class and definition in derived class
    public:
        int tyreSize;
        int engineSize;

        // Declaration of pure virtual function in Base class
        virtual void calculateMileage() = 0; 
        virtual void refuel() = 0;
};

class Bike : public Vehicle {
    public:
        int handleSize;

        // Now it is mandatory to have the Defination of all the pure virtual funtion from Base class in derived class
        void calculateMileage() {
            cout<<"Calculated mileage"<<endl;
        }

        void refuel() {
            cout<<"refueled."<<endl;
        }
    
};

int main() {
    Bike honda;
    
}