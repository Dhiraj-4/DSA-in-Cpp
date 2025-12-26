#include<iostream>
using namespace std;
int main() {
    float price, selling;
    cout<<"Enter price: ";
    cin>>price;
    cout<<"Enter selling price: ";
    cin>>selling;

    if(price > selling) cout<<"Loss of "<<price-selling<<endl;

    else if(price < selling) cout<<"Profit of "<<selling-price<<endl;

    else cout<<"No profit No loss"<<endl;

}