#include<iostream>
using namespace std;
int main() {
    char str[] = "Hello World!!!"; // valid, complier appends '\0' at the end by itself, so cout knows where to stop.
    cout<<str<<endl;

    // confirming strings end with '\0' 
    for(int i = 0; str[i] != '\0'; i++) cout<<str[i];
    cout<<endl;
    
    char str1[] = {'a', 'b', 'c', 'd', 'e'}; // valid, but can't print using cout (t’s that the program behavior is undefined because cout keeps reading memory until it accidentally finds '\0'.
    char str2[] = {'a', 'b', 'c', 'd', 'e', '\0'}; // valid and can be printed using cout because of null character at end
    cout<<str2<<endl; // can be printed like this because it has '\0' at the end, if not then t’s that the program behavior is undefined because cout keeps reading memory until it accidentally finds '\0'.

}