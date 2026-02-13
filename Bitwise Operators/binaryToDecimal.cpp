#include<iostream>
#include<vector>
using namespace std;
long long binaryToDecimal(string& binary) {
    long long decimal = 0;

    long long power = 0;

    for(int i = binary.size()-1; i >= 0; i--) {
        if(binary[i] == '1') decimal += ((long long)1 << power);
        power++;
    }
    
    return decimal;
}

int main() {
    string binary = "1111";
    cout<<binaryToDecimal(binary)<<endl;
}