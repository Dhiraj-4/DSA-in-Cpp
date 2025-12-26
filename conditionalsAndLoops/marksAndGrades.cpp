#include<iostream>
using namespace std;
int main() {
    int x;
    cin>>x;
    if(x < 0 || x > 100) cout<<"Invalid Marks."<<endl;
    else if(x >= 91 && x <= 100) cout<<"Excellent"<<endl;
    else if(x >= 81 && x <= 90) cout<<"Very Good"<<endl;
    else if(x >= 71 && x <= 80) cout<<"Good"<<endl;
    else if(x >= 61 && x <= 70) cout<<"Can do better"<<endl;
    else if(x >= 51 && x <= 60) cout<<"Average"<<endl;
    else if(x >= 40 && x <= 50) cout<<"Below average"<<endl;
    else cout<<"Fail"<<endl;
}