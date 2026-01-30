#include<iostream>
#include<vector>
using namespace std;
void display(vector<int>& nums) {
    for(int ele : nums) cout<<ele<<" ";
    cout<<endl;
}

void merge(vector<int>& nums, int low, int mid, int high) {
    vector<int> temp;
    int left = low;
    int right = mid+1;

    while(left <= mid && right <= high) {
        if(nums[left] <= nums[right]) 
            temp.push_back(nums[left++]);
        else
            temp.push_back(nums[right++]);
    }

    while(left <= mid) temp.push_back(nums[left++]);
    while(right <= high) temp.push_back(nums[right++]);

    for(int i = low; i <= high; i++) nums[i] = temp[i - low];
}
void mergeSort(vector<int>& nums, int low, int high) {
    if(low >= high) return;

    int mid = (low + high) / 2;
    mergeSort(nums, low, mid);
    mergeSort(nums, mid+1, high);

    merge(nums, low, mid, high);
}
int main() {
    vector<int> nums = {6,3,45,4,8,4,2,1,8,78,5,6,32};

    display(nums);
    mergeSort(nums, 0, nums.size()-1);
    display(nums);
}