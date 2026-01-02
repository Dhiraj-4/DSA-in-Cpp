#include<iostream>
using namespace std;
int main() {
    int arr[6] = {2,3,1,5,9,7};

    for(int i = 0; i < 6; i++) {
        bool swapped = false;
        for(int j = 0; j < 6-i-1; j++) {
            if(arr[j] > arr[j+1]) {
                swap(arr[j], arr[j+1]);
                if(!swapped) swapped = true;
            }
        }
        if(!swapped) break;
    }

    for(int i = 0; i < 6; i++) {
        cout<<arr[i]<<" ";
    }
}