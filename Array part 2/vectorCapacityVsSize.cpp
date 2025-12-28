#include<iostream>
#include<vector>
using namespace std;
int main() {
    vector<int> v;

    // when ever capacity of full vector doubles it's capacity, 
    // capacity will not reduce once increased

    // size of vector changes according to assigned index
    v.push_back(6);
    v.push_back(8);
    v.push_back(5);
    v.push_back(3);
    v.push_back(6);
    v.push_back(8);
    v.push_back(5);
    v.push_back(3);
    v.push_back(6);
    v.push_back(8);
    v.push_back(5);
    v.push_back(3);
    v.push_back(6);
    v.push_back(8);
    v.push_back(5);
    v.push_back(3);
    v.push_back(6);
    v.push_back(8);
    v.push_back(5);
    v.push_back(3);
    v.push_back(6);
    v.push_back(8);
    v.push_back(5);
    v.push_back(3);
    v.push_back(6);
    v.push_back(8);
    v.push_back(5);
    v.push_back(3);
    v.push_back(6);
    v.push_back(8);
    v.push_back(5);
    v.push_back(3);
    v.push_back(6);
    v.push_back(8);
    v.push_back(5);
    v.push_back(3);

    cout<<"Size of vector "<<v.size()<<endl;
    cout<<"Capacity of vector "<<v.capacity()<<endl;

    v.pop_back();
    v.pop_back();
    v.pop_back();
    v.pop_back();
    v.pop_back();
    v.pop_back();
    v.pop_back();
    v.pop_back();
    v.pop_back();
    v.pop_back();

    v.pop_back();
    v.pop_back();
    v.pop_back();
    v.pop_back();
    v.pop_back();

    cout<<"Size of vector "<<v.size()<<endl;
    cout<<"Capacity of vector "<<v.capacity()<<endl;
}