// https://atcoder.jp/contests/dp/tasks/dp_f

#include <iostream>
#include <vector>

using namespace std;
void max_self(int &a, int b) { a = max(a, b); }
int main() {
  string s, t;
  cin >> s;
  cin >> t;
  vector<vector<int>> dp(s.length() + 1, vector<int>(t.length() + 1, 0));
  // dp[i][j] - the max total length so far
  for (int i = 0; i < (int)s.length(); i++) {
    for (int j = 0; j < (int)t.length(); j++) {
      if (s[i] == t[j]) {
        max_self(dp[i + 1][j + 1], dp[i][j] + 1);
      }
      max_self(dp[i + 1][j], dp[i][j]);
      max_self(dp[i][j + 1], dp[i][j]);
    }
  }

}