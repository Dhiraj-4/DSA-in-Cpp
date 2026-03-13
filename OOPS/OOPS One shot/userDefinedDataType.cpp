#include<iostream>
using namespace std;

class Students {
    private:
        int rollNo = -1;
        double cgpa = -1;
        string name = "NaN";

    public:

    Students (Students& p) {
        // default copy constuctor, creates shallow copy of the objects by just copying the values of each data member
        // which is bad when it comes to having pointers as data members, because it will make both the pointers point
        // at the same address which will create problems, so solve this we write custom copy constructors that helds 
        // pointers data members example : this->m = new int(*m);
    }

    Students(string name, double cgpa, int rollNo) {
        if(name.length() < 1 || name.length() > 26) {
            cout<<"got rejected!!"<<endl;
            throw "Invalid name";
            return;
        }
        if(cgpa < 0 || cgpa > 10) {
            cout<<"got rejected!!"<<endl;
            throw "Invalid cgpa";
            return;
        }
        if(rollNo < 1 || rollNo > 5000) {
            cout<<"got rejected!!"<<endl;
            throw "Invalid rollNo";
            return;
        }

        this->name = name;
        this->cgpa = cgpa;
        this->rollNo = rollNo;
    }

    Students() {
        // default constructor
    }

    Students(int s) {
        cout<<"parameterized constructor 1"<<endl;
    }

    Students(int s, int sb) {
        cout<<"parameterized constructor 2"<<endl;
    }

    int getRollNo() { 
        if(this->rollNo == -1) {
            throw "RollNo not set";
        }
        return this->rollNo; 
    }

    double getCgpa() { 
        if(this->cgpa == -1) { throw "CGPA not set"; }
        return this->cgpa; 
    }

    string getName() { 
        if(this->name == "") { throw "Name not set"; }
        return this->name; 
    }

    Students& setName(string name) {
        this->name = name;
        return *this;
    }

    Students& setCgpa(double cgpa) {
        this->cgpa = cgpa;
        return *this;
    }

    Students& setRollNo(int rollNo) {
        this->rollNo = rollNo;
        return *this;
    }
};

int main() {
    Students raghav("Raghav", 5, 56);
    

    cout<<raghav.getName()<<endl;
    cout<<raghav.getRollNo()<<endl;
    cout<<raghav.getCgpa()<<endl;

    Students dhiraj;

    Students s2(4);

    Students s3(5,6);


}