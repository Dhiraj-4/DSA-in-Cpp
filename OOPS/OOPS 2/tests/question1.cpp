#include<iostream>
using namespace std;

class Player {
public:
    int score = 10;

    Player& setScore(int score) {
        this->score = score;
        return *this;
    }
};

int main() {
    Player p;

    p.setScore(20).setScore(50);

    cout << p.score << endl;

    // 1️⃣ Output?
    // Output: 50

    // 2️⃣ Why?
    // first we created Player p; which has data member score = 10; 
    // and then we update it twice using the member function setScore first 20 and then 50 
    // and yes setScore() returns refrence to the Player object itself
}