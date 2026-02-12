#include<iostream>
#include<vector>
using namespace std;

    vector<int> corpFlightBookings(vector<vector<int>>& bookings, int n) {
        int m = bookings.size();
        vector<int> reserved(n,0);


        for(int i = 0; i < m; i++) {
            reserved[bookings[i][0] - 1] += bookings[i][2];
            if(bookings[i][1] < n) reserved[bookings[i][1]] += -(bookings[i][2]);
        }

        for(int j = 1; j < n; j++) {
            reserved[j] += reserved[j - 1];
        }

        return reserved;
    }

int main() {
    vector<vector<int>> bookings = {{1,2,10},{2,3,20},{2,5,25}};
    int n = 5;

    
    for(int ele : corpFlightBookings(bookings, n)) { // answer = [10,55,45,25,25]
        cout<<ele<<" ";
    }
    // [[1,2,10],[2,3,20],[2,5,25]]

    //  0  1  2   3   4   5
    // 10  0 -10   0   0
    //  0 20   0 -20   0
    //  0 25   0   0   0    

    // 10 45  -10 -20  0
    // 10 55  45  25   25 
}