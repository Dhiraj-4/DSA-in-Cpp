#include<iostream>
using namespace std;
void swapWithPointer(int *a, int *b) {
    int temp = *a;
    *a = *b;
    *b = temp;

    return;
}
void swapByRefrence(int &a, int &b) {
    int temp = a;
    a = b;
    b = temp;
    return;
}
int main() {
    int x = 3, y = 8;

    cout<<x<<" "<<y<<endl;

    swapWithPointer(&x, &y);

    swapByRefrence(x, y);

    cout<<x<<" "<<y<<endl;
}