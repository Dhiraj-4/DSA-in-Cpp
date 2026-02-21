#include<iostream>
#include<vector>
using namespace std;

        int longestSubarray(vector<int>& nums) {

        int maxEle = nums[0];
    
        for(int ele : nums) maxEle = max(maxEle, ele);

        int maxCnt = 0;
        int cnt = 0;

        for(int i = 0; i < nums.size(); i++) {
            if(nums[i] == maxEle) cnt += 1;
            else cnt = 0;
            
            maxCnt = max(cnt, maxCnt);
        }

        return maxCnt;
    }

int main() {
    vector<int> nums = {1,2,3,3,2,2};
    
    cout<<longestSubarray(nums)<<endl;
}