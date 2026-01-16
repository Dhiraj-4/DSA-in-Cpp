#include<iostream>
#include<vector>
using namespace std;
void subArrays
(
    vector<int>& nums, 
    vector<vector<int>>& result, 
    int idx, 
    vector<int>& temp,
    bool skipped
) {
    if(!skipped && temp.size() != 0) result.push_back(temp);
    if(idx == nums.size() || skipped) return;

    temp.push_back(nums[idx]);
    if(!skipped) subArrays(nums, result, idx+1, temp, false);
    temp.pop_back();
    if(temp.size() == 0) {
        skipped = false;
    }else{
        skipped = true;
    }
    if(!skipped) subArrays(nums, result, idx+1, temp, skipped);
}
int main() {
    vector<int> nums = {1,2,2};
    vector<vector<int>> result;
    vector<int> temp;

    subArrays(nums, result, 0, temp, false);

    for(vector<int> i: result) {
        for(int j : i) cout<<j<<" ";
        cout<<endl;
    }

    // printing sub arrays using for-loops 
    // for(int i = 0; i < nums.size(); i++) {
    //     for(int j = i; j < nums.size(); j++) {
    //         for(int k = i; k <= j; k++) cout<<nums[k]<<" ";
    //         cout<<endl;
    //     }
    // }
}