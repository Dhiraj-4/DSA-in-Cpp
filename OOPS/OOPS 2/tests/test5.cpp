#include<iostream>
using namespace std;

class Player {
public:
    int score = 50;
};

Player& badFunction() {
    Player p; // this is fine
    return p; // but this is not beause p is created with this function and will get destoryed with this function
    // this will throw an error
}

int main() {
    Player& ref = badFunction(); // we get the refrence of p , 
    // but p got destoryed with the function so Player& ref will point to a dead memory

    cout << ref.score << endl;
}