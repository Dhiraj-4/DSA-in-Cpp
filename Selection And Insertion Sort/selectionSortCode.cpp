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

    for(int i = 0; i < nums.size(); i++) {
        int key = i;
        for(int j = i+1; j < nums.size(); j++) {
            if(nums[key] > nums[j]) key = j;
        }
        if(i != key) swap(nums[i], nums[key]);
        cout<<nums[i]<<" ";
    }
}