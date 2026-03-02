#include<iostream>
#include<vector>
using namespace std;

    int numOfSubarrays(vector<int>& nums, int k, int threshold) {
        int i = 0, j = 0, cnt = 0, n = nums.size();

        double sum = 0;

        while(j < n) {
            sum += nums[j];

            if(j-i+1 >= k) {
                if(sum/k >= threshold) cnt++;
                sum -= nums[i];
                i++;
            }

            j++;
        }

        return cnt;
    }

    int main() {
        vector<int> nums = {2,2,2,2,5,5,5,8}; int k = 3, threshold = 4;

        cout<<numOfSubarrays(nums, k, threshold)<<endl;
    }