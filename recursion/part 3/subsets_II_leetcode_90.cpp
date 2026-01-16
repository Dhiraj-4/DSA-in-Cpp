#include<iostream>
#include<vector>
#include<string>
#include<algorithm>
#include<set>
using namespace std;
void bt(int idx, vector<int>& temp, vector<vector<int>>& res, set<string>& s, vector<int>& nums) {
    if(idx == nums.size()) {
    string str = "";
    for(int e : temp) str = str + (to_string(e)) + ",";

        sort(str.begin(), str.end());
        if(s.find(str) == s.end()) {
            s.insert(str);
            res.push_back(temp);
        }
        return;
    }

    temp.push_back(nums[idx]);
    bt(idx+1, temp, res, s, nums);
    temp.pop_back();
    bt(idx+1, temp, res, s, nums);
}
vector<vector<int>> subsetsWithDup(vector<int>& nums) {

    vector<vector<int>> res;
    vector<int> temp;

    set<string> s;

    bt(0, temp, res, s, nums);

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