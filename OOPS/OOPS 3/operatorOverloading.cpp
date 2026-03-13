#include<iostream>
using namespace std;

class ComplexNumber {
    public:
        int imaginary;
        int real;

        ComplexNumber(int img, int r) : imaginary(img), real(r) {};

        ComplexNumber operator+(ComplexNumber& cn) {
            int img = this->imaginary + cn.imaginary;
            int r = this->real + cn.real;

            ComplexNumber a(img, r);
            return a;
        }
};

int main() {
    ComplexNumber a(10, 5);
    ComplexNumber b(2, 3);

    ComplexNumber c = a + b;

    cout<<"imaginary : "<<c.imaginary<<" real : "<<c.real<<endl;

    // You cannot overload the following operators:
    //  . Dot operator
    //  ?: ternary operator
    //  :: scope resolution operator
    //  sizeof 
}