#include<iostream>
using namespace std;

class Cricketer {
    private:
        string name;
        int age;
        int testMatches;
        double avgTestMatchRuns;

    public:
        // setters
        Cricketer& setName(string name) {
            this->name = name;
            return *this;
        }

        Cricketer& setAge(int age) {
            this->age = age;
            return *this;
        }

        Cricketer& setTestMatches(int testMatches) {
            this->testMatches = testMatches;
            return *this;
        }

        Cricketer& setAvgTestMatchRuns(double avgTestMatchRuns) {
            this->avgTestMatchRuns = avgTestMatchRuns;
            return *this;
        }

        // getters
        string getName() {
            return this->name;
        }

        int getAge() {
            return this->age;
        }

        int getTestMatches() {
            return this->testMatches;
        }

        double getAvgTestMatchRuns() {
            return this->avgTestMatchRuns;
        }

};

int main() {
    Cricketer players[20];

    for(int i = 0; i < 20; i++) {
        string name = "";
        int age = 18;
        int testMatches = 1;
        double avgTestMatchRuns = 0.1;

        cout<<"Player "<<i+1<<endl<<endl;

        cout<<"Enter player name: ";
        cin>>name;

        cout<<"Enter age: ";
        cin>>age;

        cout<<"Enter no. of test matches: ";
        cin>>testMatches;

        cout<<"Enter avg test match runs: ";
        cin>>avgTestMatchRuns;
        cout<<endl;


        players[i].setName(name)
        .setAge(age)
        .setAvgTestMatchRuns(avgTestMatchRuns)
        .setTestMatches(testMatches);

    }
    cout<<endl<<"These are the players and their records: "<<endl;

    for(int i = 0; i < 20; i++) {

        cout<<"Player "<<i+1<<endl<<endl;

        cout<<"Name: "<<players[i].getName()<<endl;

        cout<<"Age: "<<players[i].getAge()<<endl;

        cout<<"No. of test matches: "<<players[i].getTestMatches()<<endl;

        cout<<"Avg test match runs: "<<players[i].getAvgTestMatchRuns()<<endl;
        cout<<endl;
    }
}