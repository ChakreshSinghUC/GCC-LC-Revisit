#include <algorithm>
#include <stdio.h>
#include <vector>

using namespace std;
// https://leetcode.com/problems/minimize-maximum-pair-sum-in-array/?envType=daily-question&envId=2023-11-01

class Solution {
public:
  int minPairSum(vector<int> &nums) {

    if (nums.size() == 2)
      return nums[0] + nums[1];
    // O(NlogN)
    sort(nums.begin(), nums.end());
    int N = nums.size();

    long long i = 0;
    int ans = INT_MIN;
    while (i < N / 2) {
      // brute force O(N)
      ans = max(ans, nums[i] + nums[N - i - 1]);
      i++;
    }
    return ans;
  }
};