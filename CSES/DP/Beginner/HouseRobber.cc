#pragma GCC diagnostic push
#pragma GCC diagnostic ignored "-Wc++11-extensions" 

#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int rob(vector<int>& nums) {
    int n = nums.size();
    if (n == 0) return 0;
    if (n == 1) return nums[0];
    
    vector<int> dp(n, 0);
    dp[0] = nums[0];
    dp[1] = max(nums[0], nums[1]);
    
    for (int i = 2; i < n; ++i) {
        dp[i] = max(dp[i-1], dp[i-2] + nums[i]);
    }
    
    return dp[n-1];
}

int main() {
    vector<int> houses = {2, 7, 9, 3, 1};
    cout << "Maximum amount of money that can be robbed: " << rob(houses) << endl;
    return 0;
}