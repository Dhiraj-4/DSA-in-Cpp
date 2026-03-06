#include<iostream>
using namespace std;

class Student {
    public: // allow public access of data members(variables in class) and member functions(functions in class)
    // Example: Student sharma; sharma.rollNo = 3; -> this is allowed because of public
        int rollNo;
        string name;
        int score;

    private: // Doesn't allow public access of data members(variables in class) and member functions(functions in class)
    // Example: Student sharma; sharma.phoneNo = 7854697223; -> this is not allowed because of private, can only be accessed within class
        string phoneNo;

    protected: // this also doesn't allow public acces of data members and member functions, but allows inheritence
};

int main() {
    Student sharma;
    sharma.rollNo = 3;
    sharma.name = "Sharma";
    sharma.score = 93;

    cout<<sharma.rollNo<<endl;
    cout<<sharma.name<<endl;
    cout<<sharma.score<<endl;
}