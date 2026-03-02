#include<iostream>
#include<vector>
using namespace std;

    int numSubarrayProductLessThanK(vector<int>& nums, int k) {
        if(k <= 1) return 0;

        int n = nums.size();

        int i = 0, j = 0, cnt = 0;

        long long product = 1;

        while(j < n) {
            product *= nums[j];

            while(product >= k) {
                cnt += (j-i);
                product /= nums[i];
                i++;
            }

            
            j++;
        }

        while(i < j) {
            cnt += (j-i);
            product /= nums[i];
            i++;
        }
        return cnt;
    }
int main() {
    vector<int> nums = {10,5,2,6}; int k = 100; // Output: 8

    cout<<numSubarrayProductLessThanK(nums, k)<<endl;
}