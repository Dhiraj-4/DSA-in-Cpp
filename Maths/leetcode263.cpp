#include<iostream>
using namespace std;

bool isUgly(int n) {
    if(n == 1) return true;
    if(n <= 0) return false;

    for(int i = 2; i <= n/i; i++) {
        if(n % i == 0) {

            if(i != 2 && i != 3 && i != 5) return false;

            while(n % i == 0) {
                n /= i;
            }
        }
    }
    cout<<"this is n "<<n<<endl;
    if(n != 2 && n != 3 && n != 5 && n != 1) return false;

    return true;
}
int main() {
    cout<<isUgly(6)<<endl;
}