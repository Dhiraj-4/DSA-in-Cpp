#include<iostream>
#include<vector>
#include<string>
using namespace std;

string decimalToBinary(long long num) {

    string binary(64, '0');
    if(num == 0) return binary;

    bool flag = false;
    if(num < 0) {
        flag = true;
        num = -num;
    }

    int cnt = 63;

    while(num) {
        if(num % 2) binary[cnt] = '1';
        num /= 2;
        cnt--;
    }

    if(flag) {

        // flip all the bits 1's complement
        for(int i = 0; i <= 63; i++) {
            if(binary[i] == '0') binary[i] = '1';
            else binary[i] = '0';
        }

        // Add 1, 2's complement
        bool carry = true;

        for(int i = 63; i >= 0 && carry; i--) {

            if(binary[i] == '1') {
                binary[i] = '0'; // 1 + 1 = 0;
            }else {
                binary[i] = '1'; // 0 + 1 = 1;
                carry = false; // carry = 0;
            }
        }
    }

    return binary;
}
int main() {
    int num = -6;
    cout<<decimalToBinary(num)<<endl;
}