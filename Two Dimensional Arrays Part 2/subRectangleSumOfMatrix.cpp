#include<iostream>
using namespace std;

int main() {
    cout<<"Enter rows and cols numbers: ";
    int rows, cols;
    cin>>rows>>cols;

    int matrix[rows][cols];

    cout<<"Enter matrix: ";

    for(int i = 0; i < rows; i++) {
        for(int j = 0; j < cols; j++) {
            int temp;
            cin>>temp;
            matrix[i][j] = temp;
        }
    }

    cout<<"Enter 1st cordinate: ";
    int l1,r1;
    int l2, r2;

    cin>>l1>>r1;

    cout<<"Enter 2nd cordinate: ";
    cin>>l2>>r2;

    if((l1 < 0 || l1 >= rows) && (r1 < 0 || r1 >= cols)) {
        cout<<"Invalid cordinates";
        return 0;
    }else if((l2 < 0 || l2 >= rows) && (r2 < 0 || r2 >= cols)) {
        cout<<"Invalid cordinates";
        return 0;
    }
    
    int minL = min(l1, l2);
    int maxL = max(l1, l2);

    int minR = min(r1, r2);
    int maxR = max(r1, r2);

    int sum = 0;

    for(int i = 0; i < rows; i++) {
        for(int j = 0; j < cols; j++) {
            if((i >= minL && j >= minR) 
                    && 
                (i <= maxL && j <= maxR)) 
            {
                sum += matrix[i][j];
            }
        }
    }

    cout<<endl<<"Output: "<<sum;
}