#include<iostream>
#include<vector>
using namespace std;
void combination(
    int idx, 
    int sum, 
    vector<int>& temp, 
    vector<int>& candidates, 
    int target,
    vector<vector<int>>& result
) {
    if(sum == target) {
        result.push_back(temp);
        return;
    }
    if(idx == candidates.size() || sum > target) return;

    temp.push_back(candidates[idx]);
    combination(idx, sum+candidates[idx], temp, candidates, target, result);
    temp.pop_back();
    combination(idx+1, sum, temp, candidates, target, result);

}
vector<vector<int>> combinationSum(vector<int>& candidates, int target) {
    vector<vector<int>> result;
    vector<int> temp;

    combination(0, 0, temp, candidates, target, result);

    return result;
}
int main() {
    vector<int> candidates = {2,3,6,7}; 
    int target = 7;

    vector<vector<int>> result = combinationSum(candidates, target);

    for(vector<int> v : result) {
        for(int i : v) cout<<i<<" ";
        cout<<endl;
    }
}