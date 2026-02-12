#include<iostream>
#include<vector>
using namespace std;

class NumArray {
    public: 

        vector<int> pre;

    NumArray(vector<int>& nums) {
        int sum = 0;
        for(int i = 0; i < nums.size(); i++) {
            sum += nums[i];
            pre.push_back(sum);
        }
    }
    
    int sumRange(int left, int right) {
        
        if(left == 0) return pre[right];
        return pre[right] - pre[left-1];
    }
};

int main() {
    vector<int> nums = {-2, 0, 3, -5, 2, -1};
    
    // method one
    // NumArray* obj = new NumArray(nums);
    // cout<<obj->sumRange(0, 5);

    //method two
    NumArray obj(nums);

    cout<<obj.sumRange(2, 4);

}