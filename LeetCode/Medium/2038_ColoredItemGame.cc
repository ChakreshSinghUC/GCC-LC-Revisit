// https://leetcode.com/problems/remove-colored-pieces-if-both-neighbors-are-the-same-color/
// Date: 11-24-2023

#include <iostream>
#include <string>

using namespace std;

class Solution {
public:
  bool winnerOfGame(string colors) {
    // count the consecutive As and Bs
    if (colors.length() < 3)
      return false;
    int Alice = 0;
    int Bob = 0;
    int consecutiveAs = 0;
    int consecutiveBs = 0;

    for (int i = 0; i < colors.length(); i++) {
      if (colors[i] == 'A') {
        consecutiveAs++;
        if (consecutiveBs >= 3) {
          Bob += consecutiveBs - 2;
          cout << "Bob:" << Bob;
        }
        consecutiveBs = 0;
      } else {
        consecutiveBs++;
        if (consecutiveAs >= 3) {
          Alice += consecutiveAs - 2;
        }
        consecutiveAs = 0;
      }
    }
    if (consecutiveAs >= 3) {
      Alice += consecutiveAs - 2;
    }

    if (consecutiveBs >= 3) {
      Bob += consecutiveBs - 2;
    }
    return Alice > Bob;
  }
};

int main() {
  Solution obj;
  string colors = "AAAABBBB";
  obj.winnerOfGame(colors);
}