#include<iostream>
using namespace std;

class Bike { 
    // All classes have a default hidden constructor, 
    // which initialize the object, according to whatever data member,
    // and member functions
    public:
        int cc;
        double tyreSize;

    Bike (double tyreSize, int cc) { // You can also make a custom made constructor
        this->tyreSize = tyreSize;
        this->cc = cc;
        cout<<"Constructor got called!"<<endl;
    }

    ~Bike () {
        cout<<"Destuctor got called"<<endl;
    }
};

int main() {
    Bike royalEnfield(18, 350);

    cout<<royalEnfield.tyreSize<<endl;
    cout<<royalEnfield.cc<<endl;
}