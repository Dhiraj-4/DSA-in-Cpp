#include<iostream>
#define MAX INT_MAX
#define MIN INT_MIN
#include<climits>
#include<algorithm>
using namespace std;
float max(float a, float b) {
    if(a >= b) return a;
    return b;
}
float min(float a, float b) {
    if(a <= b) return a;
    return b;
}
void findK(int nums[], int n) {
    float low = MIN;
    float high = MAX;

    for(int i = 0; i < n-1; i++) {
        int a = nums[i];
        int b = nums[i+1];

        if(a >= b) low = max(low, (a+b)/2.0);
        else high = min(high, (a+b)/2.0);

        if(low > high) {
            cout<<-1;
            return;
        }
    }

    if(low-(int)low != 0) {
        low = (int)low + 1;
    }
    if(low == high) cout<<"The only valid value of K is "<<low<<endl;
    else if(low > high) cout<<-1;
    else cout<<"Range of K is ["<<low<<","<<(int)high<<"]"<<endl;
}
int main() {
    int nums[] = {5, 2, 10};
    findK(nums, 3); 
}