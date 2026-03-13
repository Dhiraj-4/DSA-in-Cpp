#include<iostream>
using namespace std;

class Scooty {
    protected:
        int bootSpace = 0;
    
    public:
        int topSpeed;
        int mileage;
    
};

class Bike : public Scooty {
    public:
        int gears;

    void getBootSpace() {
        cout<<bootSpace<<endl;
    }
};

int main() {
    Bike b1;

    b1.getBootSpace();
}