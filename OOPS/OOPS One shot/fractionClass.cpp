#include<iostream>
using namespace std;

int gcd(int a, int b) {
    while(a != 0 && b != 0) {
        if(a > b) a = a % b;
        else b = b % a;
    }

    if(b == 0) return a;
    return b;
}

int lcm(int a, int b) {
    return (a*b) / gcd(a,b);
}

class Fraction {
    public:
        int num;
        int den = 1;

    Fraction(int n, int d) {
        if(d == 0) {
            throw runtime_error("Denominator can't be zero");
        }
        this->num = n;
        this->den = d;
    }

    Fraction operator+(Fraction& f2) {
        int n = this->num * f2.den + this->den * f2.num;
        int d = this->den * f2.den;

        Fraction f(n, d);
        return f;
    }

    Fraction operator-(Fraction& f2) {
        int n = this->num * f2.den - this->den * f2.num;
        int d = this->den * f2.den;

        Fraction f(n, d);
        return f;
    }

    Fraction operator*(Fraction& f2) {
        int n = this->num * f2.num;
        int d = this->den * f2.den;

        Fraction f(n, d);
        return f;
    }

    Fraction operator/(Fraction& f2) {
        int n = this->num * f2.den;
        int d = this->den * f2.num;

        Fraction f(n, d);
        return f;
    }

    Fraction simplify() {
        int fact = gcd(num, den);
        num = num / fact;
        den = den / fact;
    }

    void display() {
        cout<<num<<" / "<<den<<endl;
    }
};

int main() {
    Fraction f1(9,9);
    Fraction f2(2,3);

    Fraction res = f1 + f2;

    res.display();
    res.simplify();
    res.display();


    Fraction f3(2,8);

    f3.simplify();
    f3.display();
    // 2 + 9  -> 18 + 27  ->  45  -> 15  ->  5
    // 3   9       27         27      9      3
}