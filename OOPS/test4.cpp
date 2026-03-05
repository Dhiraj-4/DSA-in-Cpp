#include<iostream>
using namespace std;

class Player {
public:
    int age = 18;

    void show() {
        cout << this->age << endl;
    }
};

int main() {
    Player p;

    p.age = 30;

    p.show();

    //What will this print?
    // answer: it will print 30
}