#include<iostream>
#include<vector>
#include<climits>
using namespace std;

    // my solution works in O(3n) and modifies the original give input
    int minSubArrayLen(int target, vector<int>& nums) {                    
        // target = 7, 

        // nums = [2,3,1,2,4,3]

        //             i
        //                  j
        //         0 1 2 3  4  5
        //         2 5 6 8 12 15

        int n = nums.size();

        for(int i = 1; i < n; i++) nums[i] += nums[i-1];

        if(nums[n-1] < target) return 0;

        int i = 0;
        int j = 0;
        int minLen = n;

        while(j < n) {
            if(nums[j] >= target) {
                while(i < j && (nums[j] - nums[i] >= target)) i++;
                minLen = min(minLen, j+1);
            }

            if((i-1) >= 0 && nums[j] - nums[i-1] >= target) {
                minLen = min(minLen, j-(i-1));
            }

            j++;
        }

        return minLen;
    }

    // most optimal one (works in O(2n));
    int minSubArrayLen2(int target, vector<int>& nums) {                    
        int n = nums.size();

        int i = 0;
        int j = 0;
        int minLen = INT_MAX;
        int sum = 0;

        while(j < n) {
            sum += nums[j];
            
            while(sum >= target) {
                minLen = min(minLen, j-i+1);
                sum -= nums[i];
                i++;
            }
            
            j++;
        }

        if(minLen == INT_MAX) return 0;
        return minLen;
    }
int main() {
    int target = 7; 
    vector<int> nums = {2,3,1,2,4,3};
}