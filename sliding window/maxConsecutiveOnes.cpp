#include<iostream>
#include<vector>
using namespace std;

    // my method
    int longestOnes(vector<int>& nums, int k) {
        //                    i
        //                      j
        // [1,1,1,0,0,0,1,1,1,1,0], k = 2
        
        //            i
        //                              j
        //  0 1 2 3 4 5 6 7 8 9 10 11 12 13 14 15 16 17 18
        // [0,0,1,1,0,0,1,1,1,0, 1, 1, 0, 0, 0, 1, 1, 1, 1], k = 3 max = 5
        int n = nums.size();
        int i = 0; 
        int j = 0;
        int cnt = 0;
        int maxLen = 0;

        while(j < n) {
            if(nums[j] || cnt < k) {
                if(nums[j] == 0) cnt++;
                j++;
            } else {
                while(nums[i] && i < j) i++; 
                if(nums[i] == 0) {
                    i++;
                    cnt -= 1;
                }
            }

            maxLen = max(maxLen, j-i);
        }

        return maxLen;
    }

    // clean method (has the same algo applied and has the same complexity);
    int longestOnes2(vector<int>& nums, int k) {
        int n = nums.size();

        int i = 0;
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

        return maxLen;
    }
int main() {
    vector<int> nums = {0,0,1,1,0,0,1,1,1,0,1,1,0,0,0,1,1,1,1}; 
    
    int k = 3;

    cout<<longestOnes(nums, k)<<endl;
    cout<<longestOnes2(nums, k)<<endl;
}