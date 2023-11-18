
/*
https://leetcode.com/problems/minimum-penalty-for-a-shop/
Pentalty Tracker:
             YYNY
        0st: 1101
        1nd: 0101
        2rd: 0001
        3th: 0011
        4th: 0010

//O(n) Dynamic programming approach
// Closing at ith hour means, every no show before ith hour is a penalty and
every show on and beyond ith hour is penalty.
// If we start with all shows as penalty in first traversal of the given string,
we can come back a second time and account for every no show before the ith
hour. This way, we will have both pieces of information to calculate the penalty
at the ith hour i.e.: how many no shows before the ith hour and how many shows
on and after the ith hour.

*/
#include <iostream>
#include <vector>

using namespace std;
class Solution {
public:
  int bestClosingTime(string customers) {

    if (customers.size() == 1) {
      return (customers[0] == 'Y') ? 1 : 0; // if customer comes in 0th hour, we
                                            // can close at 1st hour else at 0th
    }
    vector<int> tracker;
    int total = 0;
    for (auto c : customers) {
      int a = (c == 'Y') ? 1 : 0;
      tracker.push_back(a);
      total += a;
    }

    vector<int> penalty(customers.length() + 1);

    penalty[0] = total;
    for (int i = 1; i < penalty.size(); i++) {
      cout << i - 1 << "\t" << tracker[i - 1] << "\t" << penalty[i - 1] << endl;
      (tracker[i - 1] == 0) ? penalty[i] = penalty[i - 1] + 1
                            : penalty[i] = penalty[i - 1] - 1;
    }
    int minPenalty = INT_MAX;
    int minIndex = INT_MAX;

    for (int i = 0; i < penalty.size(); i++) {
      if (minPenalty > penalty[i]) {
        minPenalty = penalty[i];
        minIndex = i;
      }
    }
    return minIndex;
  }
};

int main() {
  Solution obj;
  cout << obj.bestClosingTime("NYNNNYYN");
  return 0;
}