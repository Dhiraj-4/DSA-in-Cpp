#include<iostream>
#include<vector>
using namespace std;

class Gun {
    public: 
        int ammo;
        int damage;
        int scope;
};

class Player {
    private:
        class Helmet {
            private:
                int hp;
                int level;

            public: 
                Helmet& setHp(int hp) {
                    this->hp = hp;
                    return *this;
                }

                Helmet& setLevel(int level) {
                    this->level = level;
                    return *this;
                }

                int getHp() {
                    return this->hp;
                }

                int getLevel() {
                    return this->level;
                }
        };
        int health = 100;
        int age = 18;
        int score = 0;
        bool isAlive = true;
        Gun gun;
        Helmet helmet;

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
        
        void getPlayerAddress() {
            cout<<this<<endl; // this works
            cout<<this->age<<endl;
            // cout<<*this.age<<endl; // but this doesn't , when "this" is a "Player *" so "*this" should give us the object itself and *this.age 
            // should be equal to this->age, this happens because of operator precedence, "." has higher precedence than "*", so it reads as *(this.age) 
            // which is obviously wrong.

            // so the right way is:
            cout<<(*this).age<<endl;

        }

        Gun& getGun() {
            return gun;
        }

        // setters
        Player& setHealth(int health) {
            this->health = health;
            return *this;
        }

        Player& setAge(int age) {
            this->age = age;
            return *this;
        }

        Player& setScore(int score) {
            this->score = score;
            return *this;
        }

        Player& setIsAlive(bool isAlive) {
            this->isAlive = isAlive;
            (*this).isAlive = isAlive; // "->" is same as (*this) , this->age  ≡  (*this).age
            return *this;
        }

        Player& setHelmet(int level) {
            Helmet *helmet = new Helmet;
            

            int health = 0;

            if(level == 1) health = 25;
            else if(level == 2) health = 65;
            else if(level == 3) health = 90;

            helmet->setLevel(level).setHp(health);

            this->helmet = *helmet;
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


    aman.setAge(21).setHealth(200).setIsAlive(true).setScore(2);

    cout<<"After update set values."<<endl<<endl;

    cout<<"Age : "<<aman.getAge()<<endl;
    cout<<"Health : "<<aman.getHealth()<<endl;
    cout<<"IsAlive : "<<aman.getIsAlive()<<endl;
    cout<<"Score : "<<aman.getScore()<<endl;

    Player harsh;

    aman.setAge(24).setHealth(165).setIsAlive(true).setScore(65);

    Player maxScorePlayer = getMaxScorePlayer(&aman, &harsh);

    cout<<maxScorePlayer.getScore()<<endl;

    harsh.getPlayerAddress();

    Player *dynamicPlayer = new Player;

    cout<<dynamicPlayer->getScore();
}