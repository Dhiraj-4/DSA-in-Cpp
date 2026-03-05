#include<iostream>
using namespace std;

class Player {
public:
    int score = 10;
};

int main() {
    Player p;
    Player* ptr = &p;

    ptr->score = 50;

    cout << p.score << endl;

    //Questions :

    // 1️⃣ What is the output?
    // answer: output will be : 50


    // 2️⃣ Why?
    // answer : because by using ptr which was pointing to p we updated the value to 50.
    //  by using prt->score = 50 which is same as (*ptr).score = 50; and as we known *ptr gives us the vlaue at &p
}
