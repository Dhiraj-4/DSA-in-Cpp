#include<iostream>
using namespace std;

class Player {// 1.2
public:
    int score = 5;
};

Player* getPlayer(Player* p) { //2.2 we receive &a 
    p->score = 20; // update a.score = 20, because p->score is same as (*p).score and (*p) is (a);
    return p; // we return (p) the pointer to (a);
}

int main() {
    Player a; // 1.1 and 1.2) we create a Player variable which has data member int score = 5;

    Player* ptr = getPlayer(&a); // 2.1) run getPlayer(&a) we are passing a's address here (go to 2.2) and 
    // we recieve a pointer to (a) and the pointer is itself the address of a, as in (p = &a) so ptr is also now equal
    // to &a;

    ptr->score = 100; // then we update a using ptr->score = 100 

    cout << a.score << endl; // it will print 100
}