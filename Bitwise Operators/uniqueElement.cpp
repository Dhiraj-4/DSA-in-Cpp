#include<iostream>
#include<vector>
using namespace std;

    // given an integer array where every element occurs twice except one occurs only once. find that unique element.
    
    int singleNumber(vector<int>& nums) {
        int uniqueNum = 0;

        for(int ele : nums) 
            uniqueNum ^= ele;
        
        return uniqueNum;
    }
int main() {
    vector<int> nums = {4,1,2,1,2};

    cout<<singleNumber(nums)<<endl;
}