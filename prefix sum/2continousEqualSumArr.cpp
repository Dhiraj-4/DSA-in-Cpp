#include<iostream>
#include<vector>
using namespace std;
// constraints: 
// 2 <= nums.size() <= 10^5
// -10^5 <= nums[i] <= 10^5

// question: 
// check if array can be partitioned into 
// 2 continuous arrys of equal sum.

bool fun(vector<int>& nums) {
    int n = nums.size();
    for(int i = 1; i < n; i++) nums[i] += nums[i-1];
    
    // 1 2 3 4
    // 1 3 6 10
    for(int i = 0; i < n-1; i++) {
        if(nums[i] == nums[n-1]-nums[i]) {
            cout<<i<<" "<<i+1;
            return true;
        }
    }
    return false;
}
int main() {
                    //  0 1 2 3 4 5 6 7 8 9  10 
    vector<int> nums = {65,2,3,4,5,6,7,8,9,10,11};

    if(!fun(nums)) cout<<"Equal continuous sum split is not possible"<<endl;
}