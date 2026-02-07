#include<iostream>
#include<vector>
using namespace std;

void display(vector<int>& nums) {
    for(int ele : nums) cout<<ele<<" ";
    cout<<endl;
}
void cycleSort(vector<int>& nums) {
    for(int i = 0; i < nums.size(); i++) {
        while(nums[i] - 1 != i) swap(nums[i], nums[nums[i] - 1]);
    }
}
int main() {
    vector<int> nums = {2,4,1,5,3};

    display(nums);
    cycleSort(nums);
    display(nums);
}