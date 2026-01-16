#include<iostream>
using namespace std;
int calculatePaths(int row, int col, int m, int n, string path) {
    if(row == m-1 && col == n-1) {
        cout<<path<<endl;
        return 1;
    }
    if(row >= m || col >= n) return 0;
    int left = 0;
    int right = 0;
    if(row < m-1) {
        left = calculatePaths(row+1, col, m, n, path+"D");
    }
    if(col < n-1) {
        right = calculatePaths(row, col+1, m, n, path+"R");
    }
    return left + right;
}
int main() {
    int m;
    int n;
    cin>>m>>n;
    string path = "";
    cout<<calculatePaths(0, 0, m, n, path)<<endl;
}