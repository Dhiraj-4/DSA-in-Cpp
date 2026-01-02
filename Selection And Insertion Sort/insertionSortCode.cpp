#include<iostream>
#include<vector>
using namespace std;
int main() {
    vector<int> nums;

    int n;
    cout<<"Enter array length: ";
    cin>>n;

    while(n) {
        int temp;
        cin>>temp;
        nums.push_back(temp);
        n--;
    }

    for(int i = 1; i < nums.size(); i++) {
        int card = nums[i];
        int j = i-1;

        while(j >= 0 && nums[j] > card) {
            nums[j+1] = nums[j];
            j--;
        }
        nums[j+1] = card;
    }

    for(int ele : nums) cout<<ele<<" ";
}