#include<iostream>
#include<vector>
using namespace std;

    int longestSubarray(vector<int>& nums) {
        int n = nums.size();
        int i = 0;
        int k = 1;
        int zeros = 0;
        int maxLen = 0;

        for(int j = 0; j < n; j++) {
            if(nums[j] == 0) zeros++;

            while(zeros > k) {
                if(nums[i] == 0) zeros--;
                i++;
            }
            maxLen = max(maxLen, j-i+1);
        }

        return maxLen-1;
    }
int main() {
    vector<int> nums = {0,1,1,1,0,1,1,0,1};

    cout<<longestSubarray(nums)<<endl;
}