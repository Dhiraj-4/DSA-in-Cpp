#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;
    void combination(
        int idx, 
        vector<int>& candidates, 
        int target, 
        vector<vector<int>>& ans,
        vector<int>& temp,
        bool prevTaken
    ) {
        if(target == 0) {
            ans.push_back(temp);
            return;
        }
        if(target < 0 || idx >= candidates.size() || candidates[idx] > target) return;

        combination(idx+1, candidates, target, ans, temp, false);

        if(idx > 0 && candidates[idx] == candidates[idx-1] && !prevTaken) return;

        temp.push_back(candidates[idx]);
        combination(idx+1, candidates, target-candidates[idx], ans, temp, true);
        temp.pop_back();
    }
    vector<vector<int>> combinationSum2(vector<int>& candidates, int target) {
        sort(candidates.begin(), candidates.end());
        vector<vector<int>> ans;
        vector<int> temp;

        combination(0, candidates, target, ans, temp, false);
        return ans;
    }
int main() {
    vector<int> candidates = {10,1,2,7,6,1,5}; 
    int target = 7;

    vector<vector<int>> result = combinationSum2(candidates, target);

    for(vector<int> v : result) {
        for(int i : v) cout<<i<<" ";
        cout<<endl;
    }
}