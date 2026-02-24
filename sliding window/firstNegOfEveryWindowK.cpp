#include<iostream>
#include<vector>
using namespace std;

    // brute force
    // vector<int> firstNegOfEveryWindow(vector<int>& nums, int k) {
    //     int n = nums.size();

    //     int firstNeg = 0;
    //     vector<int> ans;

    //     for(int i = 0; i <= n-k; i++) {

    //         for(int j = i; j < i+k; j++) {
    //             if(nums[j] < 0) {
    //                 ans.push_back(nums[j]);
    //                 break;
    //             }
    //         }
    //     }

    //     return ans;
    // }

    vector<int> firstNegOfEveryWindow(vector<int>& nums, int k) {
        
        //                       i      j
        // 0   1  2  3   4   5  6   7  8            k
        // 2, -3, 4, 4, -7, -1, 4, -2, 6  [1, 4, 5, 7]

        // ans -3 -3 -7 -7 -1 -2
        // -3 -3 -7 -7 -7 -1 -2

        int n = nums.size();
        vector<int> ans;

        vector<int> negPositions;

        int idx = -1;
        int i = 0;
        int j = 0;

        while(j < n) {
            
        }

        return ans;
    }

    int main() {
        vector<int> nums = { 2, -3, 4, 4, -7, -1, 4, -2, 6 }; // 1 <= n <= 10^5
                        // -3 -3 -7 -7 -7 -1 -2
                // nums = { 2, 3, 4, 5, 6, -2, 4, 4, 6, -1, -4, 3, 4 };
                // -2 -2 -2 -1 -1 -1 -4 
    int k = 3; // 1 <= k <= n;

    vector<int> res = firstNegOfEveryWindow(nums, k);

    for(int i = res.size()-1; i >= 0; i--) cout<<res[i]<<" ";
}