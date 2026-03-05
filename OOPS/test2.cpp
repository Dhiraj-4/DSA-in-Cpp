#include<iostream>
using namespace std;

class Player {
public:
    int score = 0;
};

Player& update(Player& p) {
    p.score = 99;
    return p;
}

int main() {
    Player a;

    Player& ref = update(a); // didn't knew we could do this datatype & variableName; allows as to store refrence 
    // to that datatype and gives as the ref / access to modify the original variable without creating copies

    ref.score = 10;

    cout << a.score << endl; 

    // output will be: 10
}