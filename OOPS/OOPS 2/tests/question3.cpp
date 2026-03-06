#include<iostream>
using namespace std;

class Player {
public:
    int score = 0;
};

Player& update(Player& p) {
    p.score = 10;
    return p;
}

int main() {
    Player a;

    update(a).score = 50;

    cout << a.score << endl;

    // 1️⃣ Output?
    // Output will be: 50

    // 2️⃣ Why does chaining work here?
    // because update is returning refrence to Player a, and then we are simply updating a.score to 50
}