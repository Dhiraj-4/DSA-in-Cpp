#include<iostream>
#include<vector>
#include<algorithm>

int min_product_subset(std::vector<int>& nums) {
    int n = nums.size();

    sort(nums.begin(), nums.end());
    
    if(nums[0] >= 0) return nums[0];
    
    int product = 1;

    for(int i = 0; i < nums.size(); ++i) {
        if(nums[i] < 0) { // num is neg

            if(product > 0) product *= nums[i]; // product is pos

            else {// product is neg
                if(i+1 < nums.size() && nums[i + 1] < 0) product *= nums[i]; // next number is nega is also neg
            }
        }
        else if(nums[i] > 0) product *= nums[i];
    }

    return product;
}

int min_product_subset2(std::vector<int>& nums) {
    int n = nums.size();

    int max_neg = INT_MIN;
    int min_pos = INT_MAX;
    int prod_pos = 1;
    int prod_neg = 1;

    int cntNeg = 0, cntZero = 0;

    for(int i = 0; i < nums.size(); ++i) {
        if(nums[i] < 0) {
            max_neg = std::max(max_neg, nums[i]);
            cntNeg += 1;
            prod_neg *= nums[i];
        }
        else if(nums[i] == 0) {
            cntZero += 1;
        }
        else {
            prod_pos *= nums[i];
            min_pos = std::min(min_pos, nums[i]);
        }
    }

    if(cntNeg == 0) {
        if(cntZero > 0) return 0;
        else return min_pos;
    }
    else {
        if(cntNeg % 2 == 0) {
            return (prod_neg / max_neg) * prod_pos;
        }
        else {
            return prod_neg * prod_pos;
        }
    }
}

int main() {
    std::vector<int> nums = {-1, -2, 0, 0, 3,4,5,6};

    std::cout<<min_product_subset(nums)<<std::endl;
    std::cout<<min_product_subset2(nums)<<std::endl;
}