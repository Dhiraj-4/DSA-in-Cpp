#include<iostream>
using namespace std;

class Player {
public:
    int score = 10;
};

void update(Player p) {
    p.score = 100;
}

int main() {
    Player a;

    update(a);

    cout << a.score << endl;

    //  1️⃣ Output?
    // the Output will be : 10

    //  2️⃣ Why didn’t a change?
    // because in update(a) function we are getting a copy of Player a not the refrence of Player a;
}