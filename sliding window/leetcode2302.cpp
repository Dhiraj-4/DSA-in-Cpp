#include<iostream>
#include<vector>
using namespace std;

    long long countSubarrays(vector<int>& nums, long long k) {
        int n = nums.size();
        int sum = 0, i = 0, j = 0, cnt = 0;

        while(j < n) {
            sum += nums[j];

            while((sum * (j-i+1)) >= k) {
                sum -= nums[i];
                i++;
            }

            cnt += (j-i+1);
            j++;
        }

        return cnt;
    }
int main() {
    vector<int> nums = {2,1,4,3,5}; int k = 10; // 6

    cout<<countSubarrays(nums, k)<<endl;
}