#include<iostream>
using namespace std;
int main() {
    int nums[] = {1, 2, 3, 4, 5, 9, 15, 18, 20, 21, 24};

    // find lower bound of target;

    int target = 20;
    int n = sizeof(nums) / sizeof(nums[0]);
    int low = 0;
    int high = n - 1;

    while(low <= high) {
        int mid = low + (high - low) / 2;

        if(nums[mid] >= target) high = mid-1;
        else low = mid+1;
    }

    cout<<low<<endl;
}