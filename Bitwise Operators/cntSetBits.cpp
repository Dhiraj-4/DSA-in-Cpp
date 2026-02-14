#include<iostream>
using namespace std;
int setBits(int num) {
    if(num == 0) return 0;

    int sb = 0;
    while(num) {
        sb++;
        num = (num & (num-1));
    }
    return sb;
}

int getSetBits(int num) {
    if(num == 0) return 0;

    int setBits = 0;

    while(num) {
        setBits += (num & 1);
        num = (num >> 1);
    }

    return setBits;
}
int main() {
    int n = 9;

    cout<<setBits(n)<<endl;
    cout<<getSetBits(n)<<endl;
    cout<<__builtin_popcount(n);
}