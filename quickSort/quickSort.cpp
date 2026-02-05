#include<iostream>
#include<vector>
using namespace std;
void display(vector<int>& nums) {
    for(int ele : nums) cout<<ele<<" ";
    cout<<endl;
}

void quickSort(vector<int>& nums, int low, int high) {
    if(low >= high) return;

    swap(nums[low], nums[(low + high) / 2]);
    
    int pivot = nums[low];
    int i = low + 1;
    int j = high;

    while(true) {
        while(i <= high && nums[i] <= pivot) i++;
        while(j > low && nums[j] > pivot) j--;

        if(i >= j) break;
        swap(nums[i], nums[j]);
    }

    swap(nums[j], nums[low]);

    quickSort(nums, low, j-1);
    quickSort(nums, j+1, high);
}

int main() {
    vector<int> nums = {5,1,8,2,3};
    // nums = {1,2,3,4,5};
    nums = {5,4,3,2,1};

    display(nums);
    quickSort(nums, 0, nums.size()-1);
    display(nums);
}