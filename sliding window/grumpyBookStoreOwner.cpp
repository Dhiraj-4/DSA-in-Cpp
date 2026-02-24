#include<iostream>
#include<vector>
using namespace std;
    // first try (messy and redundent code) but solved it without help;

    // int maxSatisfied(vector<int>& customers, vector<int>& grumpy, int minutes) {
    //     //              0 1 2 3 4 5 6 7
    //     // customers = [1,0,1,2,1,1,7,5]
    //     // grumpy =    [1,1,0,1,0,0,0,0]
    //     // minutes = 3  1 0 1 2 1 1 7 5 = 18
    //     int n = customers.size();
    //     int maxValueWindowIdx = 0;
    //     int maxValue = 0;
    //     int sum = 0;
    //     for(int i = 0; i < n; i++) {
    //         if(grumpy[i]) sum += customers[i];

    //         if(i >= minutes && grumpy[i-minutes]) sum -= customers[i-minutes];
    //         if(i >= minutes-1 && maxValue <= sum) {
    //             maxValue = sum;
    //             maxValueWindowIdx = i+1-minutes;
    //             cout<<"maxValueWindowIdx :"<<maxValueWindowIdx<<endl;
    //         } 
    //     }
    //     cout<<maxValue<<" "<<maxValueWindowIdx<<endl;
    //     sum = 0;

    //     for(int i = 0; i < n; i++) {
    //         if(i >= maxValueWindowIdx && minutes != 0) {
    //             sum += customers[i];
    //             minutes -= 1;
    //         }else if(grumpy[i] == 0) sum += customers[i];
    //     }

    //     return sum;
    // }




    // second try better but still redudent

    // int maxSatisfied(vector<int>& customers, vector<int>& grumpy, int minutes) {
    //     int n = customers.size();

    //     int maxTotalValue = 0;
    //     int lostWindowValue = 0;
    //     int maxLostWindowIdx = 0;
    //     int maxLostValue = 0;

    //     for(int i = 0; i < n; i++) {
    //         if(grumpy[i] == 0) maxTotalValue += customers[i];
    //         else lostWindowValue += customers[i];

    //         if(i >= minutes && grumpy[i-minutes]) lostWindowValue -= customers[i-minutes];

    //         if(i >= minutes-1 && maxLostValue <= lostWindowValue) {
    //             maxLostValue = lostWindowValue;
    //             maxLostWindowIdx = i-(minutes-1);
    //         }
    //     }

    //     cout<<"maxLostWindowIdx : "<<maxLostWindowIdx<<" "<<endl;
    //     cout<<"maxTotalValue : "<<maxTotalValue<<endl;
    //     // not required
    //     for(int j = maxLostWindowIdx; j < maxLostWindowIdx + (minutes); j++) {
    //         if(grumpy[j] == 1) maxTotalValue += customers[j];
    //     }
        
    //     return maxTotalValue;
    // }

    // third try cleanest
    int maxSatisfied(vector<int>& customers, vector<int>& grumpy, int minutes) {
        int n = customers.size();

        int maxTotalValue = 0;
        int lostWindowValue = 0;
        int maxLostValue = 0;

        for(int i = 0; i < n; i++) {
            if(grumpy[i] == 0) maxTotalValue += customers[i];
            else lostWindowValue += customers[i];

            if(i >= minutes && grumpy[i-minutes]) lostWindowValue -= customers[i-minutes];

            if(i >= minutes-1 && maxLostValue <= lostWindowValue) maxLostValue = lostWindowValue;
        }
        
        return maxTotalValue + maxLostValue;
    }
int main() {
    //                       0 1 2 3 4 5 6 7
    vector<int> customers = {1,0,1,2,1,1,7,5};
    vector<int> grumpy =    {0,1,0,1,1,1,0,0};
    int minutes = 3;      // 1 0 1 0 0 0 7 5 = 14 + (2 + 1 + 1)-> lost satisfaction

    cout<<maxSatisfied(customers, grumpy, minutes);
}