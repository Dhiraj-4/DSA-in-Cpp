#include<iostream>
using namespace std;

class something {
    private:
        int kaad = 36;

    public:
        int adarsh;

        friend void dost(something &a);
        friend class classFriend;
};

void dost(something &a) { 
    // friend class and function and access private members
    // of base class from outside the base class
    cout<<"I know kaad "<<a.kaad<<endl;
}

int main() {
    something a;
    dost(a);
}