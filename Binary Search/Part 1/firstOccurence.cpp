#include<iostream>
using namespace std;
int main() {
    int nums[] = {1, 2, 3, 4, 5, 5, 5, 5, 9, 15, 18, 20, 21, 24};

    // find first occurence of target;

    int target = 55;
    int n = sizeof(nums) / sizeof(nums[0]);
    int low = 0;
    int high = n - 1;

    while(low <= high) {
        int mid = low + (high - low) / 2;

        if(nums[mid] >= target) high = mid-1;
        else low = mid+1;
    }
    if (low < n && nums[low] == target) {
        cout << nums[low] << " at " << low << " index." << endl;
    } else {
        cout << "Target not found" << endl;
    }
}