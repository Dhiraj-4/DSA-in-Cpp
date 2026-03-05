#include<iostream>
#include<vector>
using namespace std;

class Player {
    private:
        int health = 100;
        int age = 18;
        int score = 0;
        int isAlive = true;

    public:
        // getters
        int getHealth() {
            return this->health;
        }

        int getAge() {
            return this->age;
        }

        int getScore() {
            return this->score;
        }

        bool getIsAlive() {
            return this->isAlive;
        }

        // setters
        Player* setHealth(int health) {
            this->health = health;
            return this;
        }

        Player* setAge(int age) {
            this->age = age;
            return this;
        }

        Player* setScore(int score) {
            this->score = score;
            return this;
        }

        Player* setIsAlive(bool isAlive) {
            this->isAlive = isAlive;
            (*this).isAlive = isAlive; // "->" is same as (*this) , this->age  ≡  (*this).age
            return this;
        }

        void getPlayerAddress() {
            cout<<this<<endl; // this works
            cout<<this->age<<endl;
            // cout<<*this.age<<endl; // but this doesn't , when "this" is a "Player *" so "*this" should give us the object itself and *this.age 
            // should be equal to this->age, this happens because of operator precedence, "." has higher precedence than "*", so it reads as *(this.age) 
            // which is obviously wrong.

            // so the right way is:
            cout<<(*this).age<<endl;

        }
};

Player& getMaxScorePlayer(Player* a, Player* b) {
    if((*a).getScore() > b->getScore()) return *a;
    else return *b;
}

int main() {
    Player aman;

    cout<<endl<<"Before update default values."<<endl<<endl;

    cout<<"Age : "<<aman.getAge()<<endl;
    cout<<"Health : "<<aman.getHealth()<<endl;
    cout<<"IsAlive : "<<aman.getIsAlive()<<endl;
    cout<<"Score : "<<aman.getScore()<<endl<<endl;;


    aman.setAge(21)->setHealth(200)->setIsAlive(true)->setScore(2);

    cout<<"After update set values."<<endl<<endl;

    cout<<"Age : "<<aman.getAge()<<endl;
    cout<<"Health : "<<aman.getHealth()<<endl;
    cout<<"IsAlive : "<<aman.getIsAlive()<<endl;
    cout<<"Score : "<<aman.getScore()<<endl;

    Player harsh;

    aman.setAge(24)->setHealth(165)->setIsAlive(true)->setScore(65);

    Player maxScorePlayer = getMaxScorePlayer(&aman, &harsh);

    cout<<maxScorePlayer.getScore()<<endl;

    harsh.getPlayerAddress();

    Player *dynamicPlayer = new Player;

    cout<<dynamicPlayer->getScore();
}