#include<iostream>
#include<vector>
using namespace std;
int main() {
    vector<int> v(5,10); // initial size = 5, and default value of each element is 10;

    cout<<"Size of vector "<<v.size()<<endl;
    cout<<"Capacity of vector "<<v.capacity()<<endl;
    cout<<"random element from vector (default value) "<<v[3]<<endl;
}