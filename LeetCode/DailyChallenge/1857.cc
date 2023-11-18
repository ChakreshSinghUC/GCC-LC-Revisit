#include <bits/stdc++.h>

using namespace std;
// https://leetcode.com/problems/minimize-maximum-pair-sum-in-array/?envType=daily-question&envId=2023-11-01
// 1. sort the given array
// 2. take the sums of the pairs made by taking 1 element from the sorted array
// from both ends
// 3. return the max sum of all such pair sums

// Logical proof of correctness : In short - Nature loves symmetry - And the law
// of symmetry dictates that a sorted array with elements from both ends looks
// more beautiful than anything else. Formally, this can be proven by
// contradiction. In a sorted array a0, a1, ... , a9 (for example) - the minimum
// maximum sum that has one element as a9, has to one of the pairs : (a0, a9),
// (a1, a9) ... (a8, a9). since a0 is the smallest, the mim max sum that has a9
// as an element = a0+a9. Similarly, for a8, its = a1+a8. So on an so forth.

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