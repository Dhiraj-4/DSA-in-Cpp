#include<iostream>
using namespace std;


class Vehicle {
    public:
        inline static int noOfVehicle = 0;
        string a = "Vechile_ka_a";

    private:
        string b = "Vechile_ka_b";

    protected:
        string c = "Vechile_ka_c";
        string d = "Vechile_ka_d";

        Vehicle() {
            noOfVehicle++;
        }
};

class Bike : public Vehicle { 
    // All classes have a default hidden constructor, 
    // which initialize the object, according to whatever data member,
    // and member functions
    public:
        int cc;
        double tyreSize;

    Bike () {

    }

    Bike (double tyreSize, int cc) { // You can also make a custom made constructor
        this->tyreSize = tyreSize;
        this->cc = cc;
        cout<<"Constructor got called!"<<endl;
    }

    // Initialisation list, same as above constructor
    // Bike (double ts, int engineSize) : tyreSize(ts), cc(engineSize) { 
        
    // }

    void call() {
        cout<<this->a<<endl;
        cout<<this->c<<endl;
        cout<<this->d<<endl;
    }

    ~Bike () {
        cout<<"Destuctor got called"<<endl;
    }

    Bike (Bike& b) {
        // how to right this copy constructor to understand how it works
        cout<<"Copy constructor got called!!"<<endl;
    }
};

int main() {
    Bike royalEnfield(18, 350);
    Bike royalEnfield2 = royalEnfield; // will call copy constructor
    Bike copyRoyalEnfield3(royalEnfield); // this also called copy constructor

    royalEnfield2 = royalEnfield; // this does not call copy constructor

    royalEnfield.cc = 650;


    Vehicle* honda = new Bike(16, 240); // why is this not allowed

    cout<<royalEnfield2.cc<<endl;

    cout<<"Bike::noOfVehicle "<<Bike::noOfVehicle<<endl;// this is only accessible if Bike : public Vechile {}; if used private or protected 
    // cout<<royalEnfield2.a<<endl;
    royalEnfield2.call();
    // cout<<royalEnfield2.c<<endl;
    // cout<<royalEnfield2.d<<endl;


    // When your class uses dynamic memory, you must implement:

    // Rule of Three

    // 1️⃣ Copy Constructor
    // 2️⃣ Copy Assignment Operator
    // 3️⃣ Destructor

    // ~A()
    // A(const A&)
    // A& operator=(const A&)

    // Because they all deal with memory ownership.
}