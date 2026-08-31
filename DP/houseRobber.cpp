#include<iostream>
#include<vector>
#include<queue>
#include<unordered_set>
using namespace std;

#define pp pair<pair<int, int>, pair<int, int>>
//                   ele, idx        left right

class Compare {
    public:
        bool operator()(pp& a, pp& b) {
            return a.first.first < b.first.first;
        }
};

int houseRobber(vector<int>& money) {
    priority_queue<pp, vector<pp>, Compare> maxHeap;
    unordered_set<int> alert;

    int n = money.size();

    for(int i = 0; i < n; i++) {
        int left = (i == 0) ? i : i-1;
        int right = (i == n-1) ? i : i+1;

        maxHeap.push({ {money[i], i}, {left, right} });
    }

    int costRobbed  = 0;

    while(!maxHeap.empty()) {
        pp temp = maxHeap.top(); maxHeap.pop();

        int cur = temp.first.second;
        int left = temp.second.first;
        int right = temp.second.second;

        if( alert.find(left) != alert.end() || alert.find(right) != alert.end() ) {
            
            if(alert.find(cur) == alert.end()) {
                // rob cur
                costRobbed += money[cur];
                
                int i = (left == 0) ? i : left-1;
                int j = (right == n-1) ? i : right+1;

                alert.insert(i);
                alert.insert(j);
            }

        }
        else if( money[cur] > money[left] + money[right] ) {
                // rob cur
                costRobbed += money[cur];
                
                int i = (left == 0) ? i : left-1;
                int j = (right == n-1) ? i : right+1;

                alert.insert(i);
                alert.insert(j);
        }
        else if( money[cur] < money[left] + money[right] ) {

            alert.insert(cur);
        }
    }

    return costRobbed;
}
int main() {
    
}