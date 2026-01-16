#include<iostream>
#include<vector>
#include<cmath>
using namespace std;
    int hoursRequiredWithKSpeed(vector<int>& piles, int k) {
        int hour = 0;
        cout<<"This is hoursRequiredWithKSpeed typing, K is "<<k<<endl;
        for(int i = 0; i < piles.size(); i++) {
            hour = hour + ceil((float)piles[i] / (float)k);
            cout<<hour<<" ";
        }

        cout<<endl;
        cout<<"This is hoursRequiredWithKSpeed ending"<<endl;
        return hour;
    }
int minEatingSpeed(vector<int>& piles, int h) {
    int low = 1;
    int high = 0;
    for(int i = 0; i < piles.size(); i++) {
        if(high < piles[i]) high = piles[i];
    }

    while(low <= high) {
        int mid = low + (high - low) / 2;

        int hoursRequired = hoursRequiredWithKSpeed(piles, mid);
        if(hoursRequired > h) low = mid+1;
        else high = mid-1;
    }
    return low;
}

int main() {
    vector<int> piles = {312884470};
    int h = 312884469;
    cout<<minEatingSpeed(piles, h);
}