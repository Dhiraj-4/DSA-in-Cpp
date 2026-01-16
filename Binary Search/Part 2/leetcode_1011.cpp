#include<iostream>
#include<vector>
using namespace std;
vector<int> lowHighVector(vector<int>& weights) {
        int sum = 0;
        int highest = weights[0];
        for(int weight : weights) {
            sum += weight;
            highest = max(highest, weight);
        }
        vector<int> res(2);
        res[0] = highest;
        res[1] = sum;
        return res;
    }
    int daysRequiredWithXCapacity(vector<int>& weights, int capacity) {
        int days = 0;
        int capacityReset = capacity;
        for(int i = 0; i < weights.size(); i++) {
            if(capacity-weights[i] >= 0) {
                capacity -= weights[i];
            }else {
                capacity = capacityReset;
                days++;
                capacity -= weights[i];
            }
        }
        return days;
    }
    int shipWithinDays(vector<int>& weights, int days) {
        vector<int> lowHigh = lowHighVector(weights);
        int low = lowHigh[0];
        int high = lowHigh[1];

        while(low <= high) {
            int mid = low + (high - low) / 2;

            int requiredDays = daysRequiredWithXCapacity(weights, mid);
            
            if(requiredDays >= days) low = mid+1;
            else high = mid-1;
        }

        return low;
    }

int main() {
    vector<int> weights = {1,2,3,4,5,6,7,8,9,10};
    int days = 5;

    cout<<shipWithinDays(weights, days);
}