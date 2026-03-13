#include<iostream>
using namespace std;

class A {
public:
    int a_ka_public;

    A () {
        cout<<"A constructor got called"<<endl;
    }
};

class B : virtual public A {
    public:
    B () {
        cout<<"B constructor got called"<<endl;
    }
};

class C : virtual public A {
    public:
    C () {
        cout<<"C constructor got called"<<endl;
    }
};

class D : public B, public C {
    public:
    // Now D has 2 instance of A. because of that 
    // we can't use A's properties, the solution is the virtual keyword 
    D () {
        cout<<"D constructor got called"<<endl;
    }

    void show() {
        cout<<a_ka_public<<endl;
    }
};

int main() {
    D dOjects;
    // Now with virtual keyword 
    // we can easy access A class data members and member functions

    dOjects.a_ka_public = 10;
    dOjects.show();
}