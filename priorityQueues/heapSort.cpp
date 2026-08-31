#include<iostream>
#include<vector>

void downHeapify(std::vector<int>& nums, int idx, int end) {

    while(idx <= end) {
        int left = (2 * idx) + 1;
        int right = (2 * idx) + 2;

        if(left > end) return;
        int maxIdx = idx;
        if(nums[left] > nums[maxIdx]) maxIdx = left;
        if(right <= end && nums[right] > nums[maxIdx]) maxIdx = right;

        if(maxIdx == idx) return;
        std::swap(nums[maxIdx], nums[idx]);
        idx = maxIdx;
    }
}
void heapSort(std::vector<int>& nums) {

    int n = nums.size();
    for(int i = (n/2)-1; i >= 0; i-=1) {
        downHeapify(nums, i, n-1);
    }

    int end = n-1;
    while(end >= 0) {
        std::swap(nums[0], nums[end]);
        end-=1;
        downHeapify(nums, 0, end);
    }
}

int main() {
    std::vector<int> nums = {1,5,6,3,2,4,8,7};

    heapSort(nums);

    for(int num : nums) std::cout<<num<<" ";
}