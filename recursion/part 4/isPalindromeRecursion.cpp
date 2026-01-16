#include<iostream>
#include<vector>
using namespace std;
bool isPalindrome(vector<int>& nums, int start, int end) {
    if(start >= end) return true;
    if(nums[start] != nums[end]) return false;
    return isPalindrome(nums, start+1, end-1);
}
int main() {
    vector<int> nums = {1,2,1, 2};

    cout<<isPalindrome(nums, 0, nums.size()-1)<<endl;
}