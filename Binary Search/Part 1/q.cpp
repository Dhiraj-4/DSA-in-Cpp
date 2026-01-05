#include<iostream>
using namespace std;
int main() {
    int nums[] = {1, 2, 3, 4, 5, 6, 7, 8,  9, 10};

    // find the smallest missing non-negative element in a sorted array with distinct elements.

    int n = sizeof(nums) / sizeof(nums[0]);
    int low = 0;
    int high = n - 1;

    while(low <= high) {
        int mid = low + (high - low) / 2;

        if(nums[mid] != mid) high = mid-1;
        else low = mid+1;
    }
    cout<<low<<endl;
}