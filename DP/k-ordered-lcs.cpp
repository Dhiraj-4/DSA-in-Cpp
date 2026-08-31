#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

vector<vector<int>> dp;

int ftd(int i, int j, vector<int>& nums1, vector<int>& nums2) {
	if(i >= nums1.size() || j >= nums2.size()) return 0;

	if(dp[i][j] != -1) return dp[i][j];

	if(nums1[i] == nums2[j]) return dp[i][j] = 1 + ftd(i+1, j+1, nums1, nums2);

	return dp[i][j] = max(
		ftd(i+1, j, nums1, nums2),
		ftd(i, j+1, nums1, nums2)
	);
}

int fbu(vector<int>& nums1, vector<int>& nums2) {
	int n = nums1.size();
	int m = nums2.size();

	for(int i = n-1; i >= 0; i--) {
		for(int j = m-1; j >= 0; j--) {
			if(nums1[i] == nums2[j]) dp[i][j] = 1 + dp[i+1][j+1];
			
			else dp[i][j] = max( dp[i+1][j], dp[i][j+1] );
		}
	}

	return dp[0][0];
}
int main() {
	int n , m, k;
	cin>>n>>m>>k;

	vector<int> nums1(n);
	for(int i = 0; i < n; i++) cin>>nums1[i];

	vector<int> nums2(m);
	for(int i = 0; i < m; i++) cin>>nums2[i];

	int ans = 0;

	// top down solution:
	// dp.clear();
	// dp.resize(n+1, vector<int>(m+1, -1));
	// ans = ftd(0, 0, nums1, nums2);

	// bottom up solution:
	dp.clear();
	dp.resize(n+1, vector<int>(m+1, 0));
	ans = fbu(nums1, nums2);

	if(ans + k > n) cout<<n<<endl;
	else cout<<(ans + k)<<endl;
}