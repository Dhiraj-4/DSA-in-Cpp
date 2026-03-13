#include<iostream>
using namespace std;

class Student {
    public:
    
    const int rollNumber; // by using normal constructor this will give error, as const require initialization while declaration, 
    // but with initialization list we can do it
    int age;

    Student(int r, int a) : rollNumber(r), age(a) {
    }

    // Student(int r, int a) {  this will give as error
    //     rollNumber = r;
    //     age = a;
    // }
};

int main() {
    Student s1(100, 23);
    cout<<s1.rollNumber<<" "<<s1.age;
}