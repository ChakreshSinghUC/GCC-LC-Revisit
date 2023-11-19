// https://leetcode.com/problems/predict-the-winner/description/
// Date: 11-30-2023
// The reason why we are focusing on the score difference is because we do not
// know what the score may be at any given turn but we can say about he score
// difference with certainity as we know the two numbers at hand for any player
// to pick from
#include <iostream>
#include <vector>

using namespace std;

class Solution {
  vector<vector<int>> memo;
  int maxDiff(vector<int> nums, int l, int r, int n) {
    if (memo[l][r] != -1)
      return memo[l][r];
    if (l == r)
      return nums[l];
    int scoreByLeft = nums[l] - maxDiff(nums, l + 1, r, n);
    int scoreByRight = nums[r] - maxDiff(nums, l, r - 1, n);

    memo[l][r] = max(scoreByLeft, scoreByRight);

    return memo[l][r];
  }

public:
  bool predictTheWinner(vector<int> &nums) {
    int N = nums.size();
    memo.resize(N, std::vector<int>(N, -1));

    return maxDiff(nums, 0, N - 1, N) >= 0;
  }
};

int main() {
  vector<int> nums{1, 5, 233, 7};
  Solution obj;
  cout << obj.predictTheWinner(nums);
}
