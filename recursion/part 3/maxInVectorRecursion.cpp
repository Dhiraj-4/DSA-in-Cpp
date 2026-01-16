#include<iostream>
#include<vector>
using namespace std;
int maxInVector(vector<int>& v, int idx) {
    if(idx == v.size()-1) return v[idx];

    return max(v[idx], maxInVector(v, idx+1));
}
int main() {
    vector<int> v = {55,5,7,98,5,01,75,8,9,63,285,211,475,24,9,36,2};

    cout<<maxInVector(v, 0)<<endl;
}