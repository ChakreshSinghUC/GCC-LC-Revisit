// https://leetcode.com/problems/predict-the-winner/description/
// Date: 11-30-2023

#include <iostream>
#include <vector>

using namespace std;

class Solution {
public:
  bool predictTheWinner(vector<int> &nums) {
    for (auto n : nums)
      cout << n << ", ";
    return false;
  }
};

int main() {
  vector<int> nums{1, 5, 233, 7};
  Solution obj;
  cout << obj.predictTheWinner(nums);
}
