#include<iostream>
using namespace std;

class Vehicle {
public:
    int a_ka_public;

    void show() {
        cout<<"Vehicle ka show"<<endl;
    }
};

class Bike : public Vehicle {
    public:

    void show() {
        cout<<"Bike ka show"<<endl;
    }
};

int main() {
    Bike b;

    b.show(); // this is Bike's show
    b.Vehicle::show(); // one way to access Vehicle's show

    Vehicle* a;

    a = &b;

    a->show(); (*a).show(); // another way to access Vehicle's show, 
    // but we can also access Bike's show if we use virtual funciton like virtual void show() {} in Vehicle class
}