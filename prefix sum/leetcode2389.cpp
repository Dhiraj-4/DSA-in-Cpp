#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;
    vector<int> answerQueries(vector<int>& nums, vector<int>& queries) {
        int n = nums.size();
        int m = queries.size();

        // sort nums
        sort(nums.begin(), nums.end());

        // create pre sum array
        for(int i = 1; i < n; i++) 
            nums[i] += nums[i-1];
        

        // make res array by using binary search on nums to find answer
        vector<int> res(m);

        for(int i = 0; i < m; i++) {
            int low = 0;
            int high = n-1;

            while(low <= high) {
                int mid = (low + high) / 2;

                if(nums[mid] <= queries[i]) low = mid + 1;
                else high = mid - 1;
            }
            res[i] = low;
        }

        return res;
    }
int main() {
    vector<int> nums = {4,5,2,1};
    vector<int> queries = {3,10,21};

    for(int ele : answerQueries(nums, queries)) cout<<ele<<" ";
}