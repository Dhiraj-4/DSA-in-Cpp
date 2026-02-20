// calculate the minimum number of bit flips to convert from one number to another.

// example :

// 5 can be written as 0101 and 
// 11 can be written as 1011, so number of bit flips required will be 3.

#include<iostream>
using namespace std;
    int minBitFlips(int start, int goal) {
        // 111 = 7
        // 101 = 5

        // 010 = 7 ^ 5;
        // ans = number of set bits, 1 flip is the answer

        int temp = start ^ goal;

        int cnt = 0;

        while(temp) { // example of turning off last bit set bit: 10 & (01)
            temp = temp & (temp - 1);
            cnt += 1;
        }

        return cnt;
    }
int main() {
    int start = 5 , goal = 7; 

    cout<<minBitFlips(start, goal)<<endl;
}