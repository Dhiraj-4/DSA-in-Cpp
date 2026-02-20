#include<iostream>
#include<vector>
using namespace std;
    vector<int> singleNumber(vector<int>& nums) {
        //011
        //101

        //110 keep only the rightmost set bit, so that we can compare and seprate them.

        // x = x & -x;
 
        // with bit truned off on 3rd position

        //001
        //001
        //010
        //010
        //011

        // total xor = 011 = 3;

        // with bit turned on 3rd position

        // 101

        // total xor = 101 = 5;

        // answer = [ 3, 5];

        long long x = 0;

        for(int ele : nums) 
            x ^= ele;

        x = x & -x;

        int withSetBit = 0;
        int withoutSetBit = 0;

        for(int ele : nums) {
            if(x & ele) withSetBit ^= ele;
            else withoutSetBit ^= ele;
        }

        vector<int> ans = {withSetBit, withoutSetBit};

        return ans;
    }
int main() {

    vector<int> nums = {43772400,1674008457,1779561093,744132272,1674008457,448610617,1779561093,124075538,-1034600064,49040018,612881857,390719949,-359290212,-812493625,124732,-1361696369,49040018,-145417756,-812493625,2078552599,1568689850,865876872,865876872,-1471385435,1816352571,1793963758,2078552599,-1034600064,1475115274,-119634980,124732,661111294,-1813882010,1568689850,448610617,1347212898,-1293494866,612881857,661111294,-1361696369,1816352571,-1813882010,-359290212,1475115274,1793963758,1347212898,43772400,-1471385435,124075538,-1293494866,-119634980,390719949};

    for(int ele : singleNumber(nums)) cout<<ele<<" ";
}