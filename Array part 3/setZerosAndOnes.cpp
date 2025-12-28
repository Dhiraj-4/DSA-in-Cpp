#include<iostream>
#include<vector>
using namespace std;

void sort1(vector<int>& nums) {
    int zeros = 0;

    for(int i = 0; i < nums.size(); i++) {
        if(nums[i] == 0) zeros++;
    }

    for(int i = 0; i < nums.size(); i++) {
        if(zeros > 0) {
            nums[i] = 0;
            zeros--;
        }else nums[i] = 1;
    }
}
void display(vector<int>& nums) {
    for(int i = 0; i < nums.size(); i++) cout<<nums[i]<<" ";
    cout<<endl;
}

void sort2(vector<int>& nums) {
    int k = 0;
    for(int i = 0; i < nums.size(); i++) {
        if(nums[i] == 0) {
            nums[i] = nums[k];
            nums[k] = 0;
            k++;
        }
    }
}
int main() {
    vector<int> nums = {1,0,1,1,1,0,1,0,1,0,1,1,0,0,0,1,1};

    display(nums);
    sort1(nums);
    display(nums);


    cout<<endl<<"second sort method"<<endl;
    nums = {1,0,1,1,1,0,1,0,1,0,1,1,0,0,0,1,1};

    display(nums);
    sort2(nums);
    display(nums);
}