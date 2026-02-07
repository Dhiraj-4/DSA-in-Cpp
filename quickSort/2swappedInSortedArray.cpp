#include<iostream>
#include<vector>
using namespace std;

void display(vector<int>& nums) {
    for(int ele : nums) cout<<ele<<" ";
    cout<<endl;
}
void swap2ToSort(vector<int>& nums) {
    if(nums.size() == 1) return;

    int idx1 = 0;
    int idx2 = nums.size()-1;
    bool foundOne = false;
    for(int i = 0; i < nums.size()-1; i++) {
        if(!foundOne && nums[i] > nums[i+1]) {
            foundOne = true;
            idx1 = i;
            idx2 = i+1;
        }else if(nums[i] > nums[i+1]) {
            idx2 = i+1;
            break;
        }
    }
    if(foundOne)
        swap(nums[idx1], nums[idx2]);
}
int main() {
    vector<vector<int>> testCases = {
        {2, 1},                      // size 2, swapped
        {1},                         // size 1
        {1, 3, 2},                   // adjacent swap
        {1, 5, 3, 4, 2},             // non-adjacent swap
        {3, 8, 6, 7, 5, 9, 10},      // non-adjacent swap
        {1, 2, 4, 3, 5, 6},          // adjacent in middle
        {1, 6, 3, 4, 5, 2, 7},       // far-apart swap
        {5, 2, 3, 4, 1},             // first and last swapped
        {1, 2, 3, 5, 4},             // adjacent at end
        {4, 2, 3, 1}                 // small array, non-adjacent
    };

    for(int i = 0; i < testCases.size(); i++) {
        cout<<"TestCases "<<i<<endl;
        swap2ToSort(testCases[i]);
        display(testCases[i]);
    }
    
}