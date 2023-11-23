// https://leetcode.com/problems/frequency-of-the-most-frequent-element/description/?envType=daily-question&envId=2023-11-18

#include <iostream>
#include <vector>

using namespace std;

class Solution {
public:
  int maxFrequency(vector<int> &nums, int k) {
    if (nums.size() == 1) {
      return nums[0];
    }

    sort(nums.rbegin(), nums.rend());

    int l = 0, r = 1;
    int ans = INT_MIN;

    int leftOverK = k;
    int curr_frequency = 1;

    int hook = INT_MAX;
    bool f = false;

    while (l < r && r < nums.size()) {
      if (nums[r - 1] == nums[r]) {
        f = true;
        hook = min(hook, r - 1);
      }
      if ((nums[l] - nums[r]) < leftOverK) {
        curr_frequency++;
        leftOverK -= nums[l] - nums[r];
        ans = max(ans, curr_frequency);
      } else if (nums[l] - nums[r] == leftOverK) {
        curr_frequency++;
        ans = max(ans, curr_frequency);
        if (hook == l)
          break;
        if (f == true) {
          l = hook;
          curr_frequency = 2;
        } else {
          l = r;
          curr_frequency = 1;
        }
        r = l;
        hook = INT_MAX;
        leftOverK = k;
      } else if (nums[l] - nums[r] > leftOverK) {
        ans = max(ans, curr_frequency);
        if (hook == l)
          break;
        if (f == true) {
          l = hook;
          curr_frequency = 2;
        } else {
          l = r;
          curr_frequency = 1;
        }
        r = l;
        hook = INT_MAX;
        leftOverK = k;
      }
      r++;
    }
    return ans;
  }
};
int main()

{
  Solution obj;
  vector<int> nums{9930, 9923, 9983,  9997, 9934, 9952, 9945, 9914, 9985, 9982,
                   9970, 9932, 9985,  9902, 9975, 9990, 9922, 9990, 9994, 9937,
                   9996, 9964, 9943,  9963, 9911, 9925, 9935, 9945, 9933, 9916,
                   9930, 9938, 10000, 9916, 9911, 9959, 9957, 9907, 9913, 9916,
                   9993, 9930, 9975,  9924, 9988, 9923, 9910, 9925, 9977, 9981,
                   9927, 9930, 9927,  9925, 9923, 9904, 9928, 9928, 9986, 9903,
                   9985, 9954, 9938,  9911, 9952, 9974, 9926, 9920, 9972, 9983,
                   9973, 9917, 9995,  9973, 9977, 9947, 9936, 9975, 9954, 9932,
                   9964, 9972, 9935,  9946, 9966};
  int k = 3056;
  cout << "Ans: " << obj.maxFrequency(nums, k) << endl;
  return 0;
}