#include<iostream>
#include<vector>
#include<string>
#include<algorithm>
using namespace std;

void bt(int idx, vector<int>& temp, vector<vector<int>>& res, vector<int>& nums) {
    res.push_back(temp);

    for(int i = idx; i < nums.size(); i++) {
        if(i > idx && nums[i] == nums[i-1]) continue;

        temp.push_back(nums[i]);
        bt(i+1, temp, res, nums);
        temp.pop_back();
    }
}
vector<vector<int>> subsetsWithDup(vector<int>& nums) {
    sort(nums.begin(), nums.end());
    vector<vector<int>> res;
    vector<int> temp;


    bt(0, temp, res, nums);

    return res;
}
int main() {
    vector<int> odd1 = {1,2,3,4,5,6,7,8,10,0};

    vector<vector<int>> res = subsetsWithDup(odd1);


    cout<<"This is the result of the problem"<<endl;

    for(int i = 0; i < res.size(); i++) {
        for(int j = 0; j < res[i].size(); j++) {
            cout<<res[i][j]<<" ";
        }
        cout<<endl;
    }
}