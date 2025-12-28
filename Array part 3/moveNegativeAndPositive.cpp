#include<iostream>
#include<vector>
using namespace std;

void move(vector<int>& nums) {
    vector<int> neg;
    vector<int> pos;

    for(int i = 0; i < nums.size(); i++) {
        if(nums[i] < 0) neg.push_back(nums[i]);
        else pos.push_back(nums[i]);
    }

    for(int j = 0; j < neg.size(); j++){
        nums[j] = neg[j];
    }

    for(int k = 0; k < pos.size(); k++){
        nums[k+neg.size()] = pos[k];
    }
}
void display(vector<int>& nums) {
    for(int i = 0; i < nums.size(); i++) cout<<nums[i]<<" ";
    cout<<endl;
}

void move2(vector<int>& nums) {
    int i = 0;
    int j = nums.size()-1;

    while(i < j) {
        if(nums[i] > 0) i++;
        if(nums[j] < 0) j--;
        if(nums[i] < 0 && nums[j] > 0) {
            int temp = nums[i];
            nums[i] = nums[j];
            nums[j] = temp;
            i++;
            j--;
        }
    }
}
int main() {
    vector<int> nums = {1,-4,-1,6,1,-32,9,3,-1,7,-3,1,-6,2,8,1,1};

    cout<<"move while preserving order of the elements"<<endl;
    display(nums);
    move(nums);
    display(nums);


    cout<<endl<<"second move method that does not preserve order"<<endl;
    nums = {1,-4,-1,6,1,-32,9,3,-1,7,-3,1,-6,2,8,1,1};

    display(nums);
    move2(nums);
    display(nums);
}