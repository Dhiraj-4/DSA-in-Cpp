#include<iostream>
#include<vector>
#include<algorithm>

bool cmp(const int& a, const int& b) {
    return a > b;
}

int min_cost_to_cut_board_into_mn(std::vector<int>& x, std::vector<int>& y, int m, int n) {
    sort(x.begin(), x.end(), cmp);
    sort(y.begin(), y.end(), cmp);

    int cost = 0;

    int vertical = 1;
    int horizontal = 1;

    int i = 0, j = 0;

    while(i < m-1 && j < n-1) {

        if(x[i] > y[j]) {
            cost += (x[i] * horizontal);
            vertical += 1;
            i += 1;
        }
        else {
            cost += (y[j] * vertical);
            horizontal += 1;
            j += 1;
        }
    }

    while(i < m-1) {
        cost += (x[i] * horizontal);
        vertical += 1;
        i += 1;
    }

    while(j < n-1) {
        cost += (y[j] * vertical);
        horizontal += 1;
        j += 1;
    }

    return cost;
}

int main() {
    std::vector<int> x = {2,1,3,1,4};
    std::vector<int> y = {4, 1, 2};

    int m = 6;
    int n = 4;

    std::cout<<min_cost_to_cut_board_into_mn(x, y, m, n)<<std::endl;
}