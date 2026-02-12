#include<iostream>
#include<vector>
using namespace std;

    vector<long long> findPrefixScore(vector<int>& nums) {
        int n = nums.size();

        vector<long long> converSum(n);

        int maximum = nums[0];
        converSum[0] = nums[0] + maximum;

        for(int i = 1; i < n; i++) {
            maximum = max(nums[i], maximum);
            converSum[i] = maximum + nums[i];
            converSum[i] += converSum[i-1];
        }

        return converSum;
    }

int main() {
    vector<int> nums = {2,3,7,5,10};

    for(long long ele : findPrefixScore(nums)) cout<<ele<<" ";
}