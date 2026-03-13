#include<iostream>
using namespace std;

int main() {

    // const int x	          ->    value cannot change
    // const int* ptr	      ->    value cannot change
    // int* const ptr	      ->    pointer cannot change
    // const int* const ptr	  ->    nothing can change
    // Test(const Test& t)	  ->    object cannot be modified
    // int getX() const	      ->    function won't modify object

    const int a = 10; // this need a value initializated at the point of declaration else it gives error (complie error);

    int b = 0;
    const int* ptr = nullptr;

    // *ptr = 50; // this doesn't work, when const pointer is pointing at somthing
                //  you can't change the value using *ptr = value;

    b = 60; // but this works fine
}