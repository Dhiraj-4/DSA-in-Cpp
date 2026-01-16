#include<iostream>
#include<vector>
#include<string>
#include<algorithm>
using namespace std;

void generateSubsetsWithoutDup(
    int idx, bool prevTaken,
    vector<int>& temp, 
    vector<vector<int>>& res, 
    vector<int>& nums
) {
    if(idx == nums.size()) {
        res.push_back(temp);
        return;
    }

    generateSubsetsWithoutDup(idx+1, false, temp, res, nums);

    if(idx > 0 && nums[idx] == nums[idx-1] && !prevTaken) return;

    temp.push_back(nums[idx]);
    generateSubsetsWithoutDup(idx+1, true, temp, res, nums);
    temp.pop_back();
}
vector<vector<int>> subsetsWithDup(vector<int>& nums) {
    vector<vector<int>> res;
    vector<int> temp;

    sort(nums.begin(), nums.end());
    
    generateSubsetsWithoutDup(0, false, temp, res, nums);
    return res;
}
int main() {
    vector<int> odd1 = {1,2,3};

    vector<vector<int>> res = subsetsWithDup(odd1);


    cout<<"This is the result of the problem"<<endl;

    for(int i = 0; i < res.size(); i++) {
        for(int j = 0; j < res[i].size(); j++) {
            cout<<res[i][j]<<" ";
        }
        cout<<endl;
    }
}