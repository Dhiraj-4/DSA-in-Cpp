#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;

vector<int> findClosestElements(vector<int>& arr, int k, int x) {
    int n = arr.size();
    int low = 0;
    int high = n - 1;
    vector<int> res;
    // find lower bound

    while(low <= high) {
        int mid = low + (high - low) / 2;
        if(arr[mid] >= x) high = mid - 1;
        else low = mid + 1;
    }
    // if the x is not in the array or the it is at starting point or ending point
    // this handles that
    if(low == 0) {
        for(int i = 0; i < n; i++) {
            res.push_back(arr[i]);
            k--;
            if(k == 0) break;
        }
        return res;
    }else if(low >= n-1) {
        for(int i = n-1; i >= 0; i--) {
            res.push_back(arr[i]);
            k--;
            if(k == 0) break;
        }
        sort(res.begin(), res.end());
        return res;
    }
    int i = low;
    int j = low+1;

    while(i >= 0 && j < n) {
        int left = arr[i] - x;
        int right = arr[j] - x;

        if(left < 0) left = -left;
        if(right < 0) right = -right;

        if(left < right) {
            res.push_back(arr[i]);
            i--;
        }else if(right < left) {
            res.push_back(arr[j]);
            j++;
        }else if(left == right) {
            if(arr[i] < arr[j]) {
                res.push_back(arr[i]);
                i--;
            }
            else {
                res.push_back(arr[j]);
                j++;
            }
        }
        k--;
        if(k == 0) {
            sort(res.begin(), res.end());
            return res;
        }
    }
    while(j < n && k != 0) {
        res.push_back(arr[j]);
        j++;
        k--;
    }
    while(i >= 0 && k != 0) {
        res.push_back(arr[i]);
        i--;
        k--;
    }
    sort(res.begin(), res.end());
    return res;
}
int main() {
    vector<int> arr = {1,2,3,4,5};
    vector<int> res = findClosestElements(arr, 4, 3);

    for(int i : res) cout<<i<<" ";

    cout<<endl;
}
