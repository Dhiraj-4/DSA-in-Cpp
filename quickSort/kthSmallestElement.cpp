#include<iostream>
#include<vector>
using namespace std;

int quickSort(vector<int>& nums, int low, int high, int k) {
    if(low == high && low == k) 
        return nums[low];

    else if(low >= high) return 0; // will never get hit

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
    if(j == k) 
        return nums[j];
    
    else if(j < k) 
        return quickSort(nums, j+1, high, k);
        
    else 
        return quickSort(nums, low, j-1, k);
}

void display(vector<int>& nums) {
    for(int ele : nums) cout<<ele<<" ";
    cout<<endl;
}
int main() {
    vector<int> nums = {6,4,5,7,8,3};
    int k;

    cin>>k;
    if(k <= 0 || k > nums.size()) {
        cout<<"Invalid 1-indexed idx.";
        return 0;
    }
    display(nums);
    cout<<"The "<<k<<"th element is :"<<quickSort(nums, 0, nums.size()-1, k-1)<<endl;
    display(nums);

    // let's take k as 5 (1-indexed);
    // answer should be 7

    // mid swap to low
    // 5 4 6 7 8 3
    
    // swaping left and right accordig to pivot = 5
    // 5 4 3 7 8 6

    // swap pivot into it's correct place
    // 3 4 5 7 8 6


    // split into two calls, but only make one that has kth element, so we only make one of the two call

    // call made
    // 7 8 6

    // swap mid with low
    // 8 7 6

    // swaping left and right of pivot = 8
    // 8 7 6

    // swaping pivot into it's correct place
    // 6 7 8

    // split into two calles, but make one which has kth element
    
    // call made
    // 6 7

    // swap low with mid
    // 6 7 

    // swaping left and right for pivot = 6
    // 6 7

    // swaping pivot to correct place
    // 6 7

    // split into two calles
    
    //call made
    // 7

    // single element return

}