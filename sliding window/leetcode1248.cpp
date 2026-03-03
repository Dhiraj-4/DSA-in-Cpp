#include<iostream>
#include<vector>
using namespace std;

    int numberOfSubarrays(vector<int>& nums, int k) {
        int n = nums.size();

        //      i
        //            j
        // [1,1,2,1,1], k = 3 nice = 2, oddCount = 2, p = -1;


        //  i
        //        j
        // [2,4,6], k = 1 nice = 0, oddCount = 0, p = -1;


        //          i
        //                      j       p
        // [2,2,2,1,2,2,1,2,2,2], k = 2, nice = 16, oddCount = 1, p = 10;

        int i = 0, j = 0, nice = 0, oddCount = 0, p = -1;

        while(j < n) {
            if(nums[j] % 2 != 0) oddCount += 1;

            if (oddCount == k) {
                if(p <= j) {
                    p = j+1;

                    while(p < n && (nums[p] % 2 == 0)) p++;
                }

                while(oddCount == k && i <= j) {
                    nice += (p-j);
                    if(nums[i] % 2 != 0) oddCount--;
                    i++;
                }
            }

            j++;
        }

        return nice;
    }

    int main() {
        vector<int> nums = {2,2,2,1,2,2,1,2,2,2}; int k = 2; // 16

        cout<<numberOfSubarrays(nums, k)<<endl;
    }