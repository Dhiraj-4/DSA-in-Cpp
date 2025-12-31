#include<iostream>
using namespace std;

int main() {
    int rows1, cols1;
    int rows2, cols2;

    cout<<"Enter rows1 and cols1 ";
    cin>>rows1>>cols1;

    cout<<"Enter rows2 and cols2 ";
    cin>>rows2>>cols2;

    if(cols1 != rows2) {
        cout<<"Rows of one doesn't macth columns of second";
        return 0;
    }

    int rowsMatrix[rows1][cols1];
    int colsMatrix[rows2][cols2];


    cout<<"Enter matrices: ";
    //input rowsMatrix and colsMatrix
    for(int i = 0; i < rows1; i++) {
        for(int j = 0; j < cols1; j++) {
            int temp;
            cin>>temp;
            rowsMatrix[i][j] = temp;
        }
    }

    for(int i = 0; i < rows2; i++) {
        for(int j = 0; j < cols2; j++) {
            int temp;
            cin>>temp;
            colsMatrix[i][j] = temp;
        }
    }

    int rows3 = rows1;
    int cols3 = cols2;

    int resMatrix[rows3][cols3];

    for(int i = 0; i < rows3; i++) {
        for(int j = 0; j < cols3; j++) {
            
            int ans = 0;
            for(int k = 0; k < cols1; k++) {
                ans = ans + (rowsMatrix[i][k] * colsMatrix[k][j]);
            }
            resMatrix[i][j] = ans;
        }
    }

    cout<<endl;

    for(int m = 0; m < rows3; m++) {
        for(int l = 0; l < cols3; l++) {
            cout<<resMatrix[m][l]<<" ";
        }
        cout<<endl;
    }
}