#include<iostream>
#include<string>
#include<vector>
using namespace std;
void generatePermutations
(
    string str, 
    vector<string>& result,
    string temp
) {
    if(0 == str.size()) {
        result.push_back(temp);
        return;
    }

    for(int i = 0; i < str.size(); i++) {
        generatePermutations(str.substr(0, i)+str.substr(i+1), result, temp+str[i]);
    }
}
int main() {
    string str = "abc";

    vector<string> result;
    string temp = "";

    generatePermutations(str, result, temp);

    for(string s : result) {
        cout<<s<<" ";
    }
}