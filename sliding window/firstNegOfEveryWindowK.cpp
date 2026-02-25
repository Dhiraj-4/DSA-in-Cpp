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

        vector<int> negPositions;

        for(int i = 0; i < n; i++) {
            if(nums[i] < 0) negPositions.push_back(i);
        }
        
        vector<int> ans;

        int idx = 0;
        int i = 0;
        int j = k-1;
        
        while(j < n) {
            if(negPositions[idx] < i) idx++;
            else if(i <= negPositions[idx] && negPositions[idx] <= j) 
                ans.push_back(nums[negPositions[idx]]);

            i++;
            j++;
        }

        return ans;
    }

    int main() { 
        //                      m
        // negPositions = 1 4 5 7

        // -3 -3 -7 -7 -7 -1 -2
        //                                            i      j
        //                   0   1  2  3   4   5  6   7  8
        vector<int> nums = { 2, -3, 4, 4, -7, -1, 4, -2, 6 }; // 1 <= n <= 10^5
                        // -3 -3 -7 -7 -7 -1 -2
                // nums = { 2, 3, 4, 5, 6, -2, 4, 4, 6, -1, -4, 3, 4 };
                // -2 -2 -2 -1 -1 -1 -4 
    int k = 3; // 1 <= k <= n;

    vector<int> res = firstNegOfEveryWindow(nums, k);

    for(int i = 0; i < res.size(); i++) cout<<res[i]<<" ";
}