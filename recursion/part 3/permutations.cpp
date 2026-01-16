#include<iostream>
#include<vector>
using namespace std;
void permutations(
    vector<int>& temp, 
    vector<vector<int>>& result, 
    vector<int>& nums,
    vector<bool>& taken
) {
    if(temp.size() == nums.size()) {
        result.push_back(temp);
        return;
    }

    for(int i = 0; i < nums.size(); i++) {
        if(!taken[i]) {
            temp.push_back(nums[i]);
            taken[i] = true;
            permutations(temp, result, nums, taken);
            taken[i] = false;
            temp.pop_back();
        }
    }
}
int main() {
    vector<int> nums = {1,2,3};
    
    vector<vector<int>> result;
    vector<bool> taken(nums.size(), false);
    vector<int> temp;

    permutations(temp, result, nums, taken);

    for(vector<int>& i : result) {
        for(int j : i) cout<<j<<" ";
        cout<<endl;
    }
}