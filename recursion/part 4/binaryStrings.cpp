#include<iostream>
#include<string>
#include<vector>
using namespace std;
void binaryString(vector<string>& result, string temp, int n) {
    if(n == 0) {
        result.push_back(temp);
        return;
    }

    if(temp == "" || temp[temp.size()-1] == '0') {
        binaryString(result, temp+"0", n-1);
        binaryString(result, temp+"1", n-1);
    }else {
        binaryString(result, temp+"0", n-1);
    }
}
int main() {
    vector<string> result;
    string temp = "";
    int n;
    cin>>n;

    binaryString(result, temp, n);

    for(string s : result) {
        cout<<s<<endl;
    }
}