#define pp std::pair<double, int>
#include<iostream>
#include<vector>
#include<algorithm>
#include<unordered_map>
#include<utility>

bool cmp(const pp& a, const pp& b) {
    return a.first > b.first;
}
double fractional_knapsack(std::vector<int>& profit, std::vector<int>& weight, int w) {
    int n = profit.size();

    std::vector<pp> greatDeal(n);

    for(int i = 0; i < n; ++i) {
        greatDeal[i] = { (double)profit[i] / (double)(weight[i]) , weight[i]};
    }

    sort(greatDeal.begin(), greatDeal.end(), cmp);

    double ans = 0;

    for(int i = 0; i < n; ++i) {
        if(greatDeal[i].second <= w) {
            ans += greatDeal[i].first * (greatDeal[i].second*1.0);
            w -= greatDeal[i].second;
        }
        else {
            ans += greatDeal[i].first * (w*1.0);
            w = 0;
            break;
        }
    }

    return ans;
}
int main() {
    std::vector<int> profit = {60, 100, 120};
    std::vector<int> weight = {10, 20, 30};

    int w = 50;
    
    std::cout<<fractional_knapsack(profit, weight, w)<<std::endl;
}