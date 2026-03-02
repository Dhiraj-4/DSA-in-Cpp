#include<iostream>
#include<vector>
#include <deque>
using namespace std;

    // brute force

    vector<int> firstNegOfEveryWindow1(vector<int>& nums, int k) {
        int n = nums.size();

        int firstNeg = 0;
        vector<int> ans;

        for(int i = 0; i <= n-k; i++) {

            for(int j = i; j < i+k; j++) {
                if(nums[j] < 0) {
                    ans.push_back(nums[j]);
                    break;
                }
            }
        }

        return ans;
    }


    // better then previous solution

    vector<int> firstNegOfEveryWindow2(vector<int>& nums, int k) {
        int n = nums.size();

        vector<int> negPositions;

        for(int i = 0; i < n; i++) {
            if(nums[i] < 0) negPositions.push_back(i);
        }

        vector<int> ans;
        int m = negPositions.size();

        int idx = 0;
        int i = 0;
        int j = k-1;
        
        while(j < n) {

            while(idx < m && negPositions[idx] < i) idx++;

            if(idx < m && (i <= negPositions[idx] && negPositions[idx] <= j)) 
                ans.push_back(nums[negPositions[idx]]);
            else ans.push_back(0);

            i++;
            j++;
        }

        return ans;
    }


    // optimal
    vector<int> firstNegOfEveryWindow3(vector<int>& nums, int k) {
        int n = nums.size();
        vector<int> ans(n-k+1);

        int p = -1;
        int i = 0;
        int j = k-1;

        while(j < n) {
            if(p < i) p = i;

            while(p <= j && nums[p] >= 0) p++;

            if(p <= j) ans[i] = nums[p];
            else ans[i] = 0;

            i++;
            j++;
        }

        return ans;
    }
    

    // pratice / revision
    vector<int> firstNegOfEveryWindow4(vector<int>& nums, int k) {
        int n = nums.size();

        int i = 0, j = k-1;

        int negPos = -1;

        vector<int> ans(n-k+1, 0);

        while(j < n) {
            if(negPos < i) {
                negPos = i;
                while(negPos < n) {
                    if(nums[negPos] < 0) break;
                    negPos++;
                }
            }

            if(negPos >= i && negPos <= j) ans[i] = nums[negPos];
            
            i++;
            j++;
        }
        return ans;
    }

    int main() { 
        //                  m
        // negPositions = 1 4 5 7

        // -3 -3 -7 -7 -7 -1 -2
        //                          i      j
        //                   0   1  2  3   4   5  6   7  8
        vector<int> nums = { 2, -3, 4, 4, -7, -1, 4, -2, 6 }; // 1 <= n <= 10^5
                        // -3 -3 -7 -7 -7 -1 -2
                nums = { 2, 3, 4, 5, 6, -2, 4, 4, 6, -1, -4, 3, 4 };

                // nums = {1, 2, 3, 4, 5};
                // -2 -2 -2 -1 -1 -1 -4 
    int k = 3; // 1 <= k <= n;

    vector<int> res = firstNegOfEveryWindow1(nums, k);

    cout<<"solution 1"<<endl;
    for(int i = 0; i < res.size(); i++) cout<<res[i]<<" ";

    cout<<endl;

    vector<int> res2 = firstNegOfEveryWindow4(nums, k);
    
    cout<<"solution 4"<<endl;
    for(int i = 0; i < res2.size(); i++) cout<<res2[i]<<" ";
}