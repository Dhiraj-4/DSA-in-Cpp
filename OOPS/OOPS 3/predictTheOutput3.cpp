#include<iostream>
using namespace std;

class Student {
public:
    // inline allows defining the static member inside the class
    // without needing a separate definition like:
    // int Student::rollNumber;

    inline static int rollNumber;

    // static member functions can only access static members
    // because they don't have a 'this' pointer

    // normal member functions can access both static and non-static members

    int getRollNumber() {
        return rollNumber;
    }
};

// int Student::rollNumber = 100;
int main() {
    Student s;
    s.rollNumber = 101;
    cout<<s.getRollNumber()<<endl;
}