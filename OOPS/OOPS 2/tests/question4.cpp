#include<iostream>
using namespace std;

class Player {
public:
    int score = 5;
};

int main() {
    Player p;

    Player* ptr = &p;

    Player copy = *ptr;

    copy.score = 100;

    cout << p.score << endl;

    // 1️⃣ Output?
    // Output wil be : 5

    // 2️⃣ Why?
    // because Player copy = *ptr creates a copy of Player p, 
    // and whatever updates we do copy the original won't get effected
}