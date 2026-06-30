#include<iostream>
#include<vector>
#include<stack>
using namespace std;

vector<int> nextLargerElement(vector<int>& nums) {
    int n = nums.size();

    stack<int> st;

    vector<int> ans(n, -1);

    for(int i = n-1; i >= 0; i--) {
        while(st.size() && st.top() <= nums[i]) st.pop();

        if(st.size() == 0) {
            ans[i] = -1;
        }
        else ans[i] = st.top();
        st.push(nums[i]);
    }

    return ans;
}

int main() {
    vector<int> nums = {1,2,3,4,3};

    nums = nextLargerElement(nums);

    for(int val : nums) cout<<val<<" ";

    cout<<endl;
}