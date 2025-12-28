#include<iostream>
using namespace std;

int main() {
    int arr[1500] = {1, 3,23,2,4,23,1};

    int size = sizeof(arr) / sizeof(arr[0]);

    for(int i = 0; i < size; i++) {
        cout<<arr[i]<<" ";
    }

    int *ptr = arr + 1;
    cout<<endl;
    cout<<arr<<endl;
    cout<<ptr<<endl;

}