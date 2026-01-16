#include<iostream>
#include<vector>
using namespace std;

void generateSubSeqOfLenK
(
    int i, 
    vector<int>& temp, 
    vector<vector<int>>& res, 
    int n,
    int k,
    int len
) {
    if(len == k) {
        res.push_back(temp);
        return;
    }
    if(i > n) return;

    temp.push_back(i);
    generateSubSeqOfLenK(i+1, temp, res, n, k, len+1);
    temp.pop_back();
    generateSubSeqOfLenK(i+1, temp, res, n, k, len);
}

int main() {
    int n;
    cin>>n;
    int k;
    cin>>k;

    vector<vector<int>> res;
    vector<int> temp;

    generateSubSeqOfLenK(1, temp, res, n, k, 0);

    for(vector<int> i : res) {
        for(int j : i) cout<<j<<" ";
        cout<<endl;
    }
}