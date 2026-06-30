#include<iostream>
#include<queue>
#include<vector>
using namespace std;
// { 0, -1, -2, 3, 4, -5, 6, 4, 7, -8 };

void display(vector<int>& v) {
    for(int i = 0; i < v.size(); i++) cout<<v[i]<<" ";
    
    cout<<endl;
}
int main() {
    int n = 10;
    int k = 3;
    vector<int> nums = { 0, -1, -2, 3, 4, -5, 6, 4, 7, -8 };
    queue<int> q;


    for(int i = 0; i < k-1; i++) if(nums[i] < 0) q.push(i);

    vector<int> ans(n-k+1, 0);

    int i = 0;

    display(nums);
    while(i < n-k+1) { // 8
        if(nums[i+k-1] < 0) q.push(i+k-1);
        if(q.size() && q.front() < i) q.pop();
        if(q.size() && q.front() < i+k && q.front() >= i) ans[i] = nums[q.front()];
        else ans[i] = 0;
        i++;
    }

    display(ans);
}