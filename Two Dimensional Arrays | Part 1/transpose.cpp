    #include<iostream>
    #include<vector>
    using namespace std;

    vector<vector<int>> transpose(int rows, int cols, vector<vector<int>>& nums) {
        vector<vector<int>> ans(cols, vector<int>(rows));

        for(int i = 0; i < rows; i++) {
            for(int j = 0; j < cols; j++) {
                ans[j][i] = nums[i][j];
            }
        }
        return ans;
    }
    void display(vector<vector<int>>& nums) {
        int n = nums.size();
        int m = nums[0].size();

        for(int i = 0; i < n; i++) {
            for(int j = 0; j < m; j++) {
                cout<<nums[i][j]<<" ";
            }
            cout<<endl;
        }
    }
    int main() {
        int rows;
        cout<<"Enter rows size of array: ";
        cin>>rows;

        int cols;
        cout<<"Enter columns size of array: ";
        cin>>cols;

        vector<vector<int>> nums(rows, vector<int>(cols));

        for(int i = 0; i < rows; i++) {
            for(int j = 0; j < cols; j++) {
                int temp;
                cin>>temp;
                nums[i][j] = temp;
            }
        }

        vector<vector<int>> answer = transpose(rows, cols, nums);

        display(answer);
    }