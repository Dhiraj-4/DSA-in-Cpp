#include<iostream>
#include<vector>
#include<climits>
using namespace std;
int main() {
    vector<int> nums = {19, 12, 23, 8, 16};
    int cnt = 0;
    int n = nums.size();
    bool visited[n] = {false};

    for(int i = 0; i < n; i++) cout<<nums[i]<<" ";

    cout<<endl;
    
    for(int i = 0; i < n; i++) {
        int key = i;
        int ele = INT_MAX;
        for(int j = 0; j < n; j++) {
            if(ele > nums[j] && visited[j] == false) {
                key = j;
                ele = nums[j];
            }
        }
        nums[key] = cnt++;
        visited[key] = true;
    }

    for(int i = 0; i < n; i++) cout<<nums[i]<<" ";

    
}