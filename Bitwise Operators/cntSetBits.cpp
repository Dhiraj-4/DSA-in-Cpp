#include<iostream>
using namespace std;
int main() {
    int n = 2;

    int setBits = 0;

    while(n) {
        if( (n & 1) == 0) setBits++;
        n = (n >> 1);
    }
 
    cout<<setBits<<endl;
    cout<<__builtin_popcount(2)<<endl;
}