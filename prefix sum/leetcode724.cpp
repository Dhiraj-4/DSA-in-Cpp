#include<iostream>
#include<vector>
using namespace std;

    int pivotIndex(vector<int>& nums) {
        // [1,7, 3, 6, 5, 6]

        //  0 1  2  3  4  5
        //  1 8 11 17 22 28
        //          i  
            // 11 == 11

        int n = nums.size();

        // create prefix array
        for(int i = 1; i < n; i++)
            nums[i] += nums[i-1];


        //find pivot idx
        for(int i = 0; i < n; i++) {
            int left = ((i == 0) ? 0 : nums[i-1]);
            int right = nums[n-1] - nums[i];

            if(left == right) return i;
        }
        
        // no pivot index found
        return -1;
    }
int main() {
    vector<int> nums = {1,7,3,6,5,6};

    cout<<pivotIndex(nums);
}