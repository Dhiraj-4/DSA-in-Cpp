#include<iostream>
#include<vector>
using namespace std;

int cntPairs(vector<int>& nums, int low, int mid, int high) {
    int cnt = 0;
    int left = low;
    int right = mid+1;

    while(left <= mid) {
        while(right <= high && 2 * (long long)nums[right] < (long long)nums[left]) right++;
        left++;
        cnt += (right - (mid+1));
    }

    return cnt;
}
int merge(vector<int>& nums, int low, int mid, int high) {
    int cnt = cntPairs(nums, low, mid, high);
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

    return cnt;
}
int mergeSort(vector<int>& nums, int low, int high) {
    int cnt = 0;
    if(low >= high) return 0;

    int mid = (low + high) / 2;

    cnt += mergeSort(nums, low, mid);
    cnt += mergeSort(nums, mid+1, high);

    cnt += merge(nums, low, mid, high);

    return cnt;
}
void display(vector<int>& nums) {
    for(int ele : nums) cout<<ele<<" ";
    cout<<endl;
}
int main() {
    vector<int> nums = {5,1,8,2,3};

    display(nums);
    cout<<mergeSort(nums, 0, nums.size()-1)<<endl;
    display(nums);
}