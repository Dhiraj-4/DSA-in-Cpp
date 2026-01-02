#include<iostream>
#include<vector>
#include<sstream>
#include<algorithm>
using namespace std;
int main() {
    string str = "Hello, i will let the world burn, i will let it burn, look what you made me become, i know you think you run, i will let world burn";
    stringstream ss(str);

    vector<string> v;
    string temp;
    while(ss>>temp) {
        v.push_back(temp);
    }

    sort(v.begin(), v.end());

    int maxCount = 0;
    int cnt = 1;
    for(int i = 0; i < v.size()-1; i++) {
        if(v[i] == v[i+1]) cnt++;
        else cnt = 1;
        maxCount = max(maxCount, cnt);
    }

    for(int i = 0; i < v.size(); i++) {
        cout<<v[i]<<endl;
    }

    string maxWord = "";
    cnt = 1;
    for(int i = 0; i < v.size()-1; i++) {
        if(v[i] == v[i+1]) cnt++;
        else cnt = 1;
        if(cnt == maxCount) maxWord = v[i];
    }

    cout<<"Your answer is : "<<maxWord<<endl;
}