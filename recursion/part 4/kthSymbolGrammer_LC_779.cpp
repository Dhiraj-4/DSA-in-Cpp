#include<iostream>
#include<cmath>
using namespace std;

// this is the recursion way
int recursion
(
    int n, int k, int start,
    int end, int value
) {
    if(n == 1) return value;

    int mid = (start + end) / 2;
    if(mid >= k) return recursion(n-1, k, start, mid, value);
    return recursion(n-1, k, mid+1, end, 1-value);
}
int kthGrammar(int n, int k) {

    int start = 1;
    int end = (1 << (n-1));
    int value = 0;
    cout<<recursion(n, k, start, end, value);

    // iterative solution 
    while(n > 1) {
        int mid = (start+end) / 2;

        if(mid >= k) end = mid;
        else {
            start = mid+1;
            value = 1 - value;
        }
        n -= 1;
    }
    return value;
}
int kthGrammar2(int n, int k) {
    if (n == 1) return 0;

    int parent;
    if(k%2) parent = kthGrammar2(n-1, (k/2)+1);
    else parent = kthGrammar2(n-1, (k/2));

    if(k%2) return parent;
    return 1 - parent;
}
int main() {

    cout<<kthGrammar2(4,1)<<" ";
    cout<<kthGrammar2(4,2)<<" ";
    cout<<kthGrammar2(4,3)<<" ";
    cout<<kthGrammar2(4,4)<<" ";
    cout<<kthGrammar2(4,5)<<" ";
    cout<<kthGrammar2(4,6)<<" ";
    cout<<kthGrammar2(4,7)<<" ";
    cout<<kthGrammar2(4,8)<<" ";
}