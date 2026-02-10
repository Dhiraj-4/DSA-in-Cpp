#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;

int maxSatisfaction(vector<int>& satisfaction) {
    sort(satisfaction.begin(), satisfaction.end());

    int n = satisfaction.size();
    int sufSum = 0;
    int totalSum = 0;
    int maxSum = 0;

    for(int i = n-1; i >= 0; i--) {
        sufSum += satisfaction[i];
        totalSum += sufSum;
        if(maxSum < totalSum) maxSum = totalSum;
        else break;
    }
    return maxSum;
}
int main() {                            // 0  1  2 3 4
    vector<int> nums = {-1,-8,0,5,-9}; // -9 -8 -1 0 5  sufSum = -13; total = 10;
                                       //  i  
    cout<<maxSatisfaction(nums)<<endl;
}