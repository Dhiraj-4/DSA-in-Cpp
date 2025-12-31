#include<iostream>
using namespace std;

int main() {
    int rows, cols;

    cout<<"Enter number of rows and number of cols: ";
    cin>>rows>>cols;

    cout<<"Enter matrix: ";
    int matrix[rows][cols];

    for(int i = 0; i < rows; i++) {
        for(int j = 0; j < cols; j++) {
            int temp;
            cin>>temp;
            matrix[i][j] = temp;
        }
    }

    for(int i = 0; i < rows; i++) {
        int j = 0;
        int flag = true;
        if(i % 2) { j = cols-1; flag = false; }

        while(j >= 0 && j < cols) {
            cout<<matrix[i][j]<<" ";
            if(flag) j++;
            else j--;
        }
        cout<<endl;
    }
}