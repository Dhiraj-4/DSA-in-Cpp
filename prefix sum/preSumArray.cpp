#include<iostream>
#include<vector>
using namespace std;
vector<int> preSumArray(vector<int>& nums) {
    vector<int> res(nums.size());
    int sum = 0;

    for(int i = 0; i < nums.size(); i++) {
        sum += nums[i];
        res[i] = sum;
    }

    return res;
}
void display(vector<int>& nums) {
    for(int ele : nums) cout<<ele<<" ";
    cout<<endl;
}
int main() {
    vector<int> nums = {1,4,5,6,2,3,4,2,7};

    vector<int> res = preSumArray(nums);

    display(nums);
    display(res);
}