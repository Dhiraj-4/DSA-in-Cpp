#include<iostream>
#include<sstream>
using namespace std;

int main() {
    string str = "Hey I am Dhiraj and I wanna be rich";

    stringstream ss(str); 
    // ss will treat each word from str as a seperate string, 
    // and put them in it's stream

    string temp;
    while(ss>>temp) { // temp is getting each word/string from ss, it's in it's stream, 
                      // after this ss only have the last word "rich" in it
        cout<<temp<<endl;
    }
}