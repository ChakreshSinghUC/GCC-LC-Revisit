// https://atcoder.jp/contests/dp/tasks
// https://atcoder.jp/contests/dp/tasks/dp_c
#include <iostream>
#include <math.h>
#include <vector>

using namespace std;

int max_happiness(int N, vector<vector<int>> &h) {
  vector<vector<int>> dp(N, vector<int>(3));

  dp[0][0] = h[0][0];
  dp[0][1] = h[0][1];
  dp[0][2] = h[0][2];

  for (int i = 1; i < N; i++) {
    dp[i][0] = max(dp[i - 1][1], dp[i - 1][2]) + h[i][0];
    dp[i][1] = max(dp[i - 1][0], dp[i - 1][2]) + h[i][1];
    dp[i][2] = max(dp[i - 1][0], dp[i - 1][1]) + h[i][2];
  }

  int ans = max(max(dp[N - 1][0], dp[N - 1][1]), dp[N - 1][2]);
  return ans;
}

int main() {
  int N;
  cin >> N;
  vector<vector<int>> happiness(N, vector<int>(3));

  for (int i = 0; i < N; i++)
    for (int j = 0; j < 3; j++)
      cin >> happiness[i][j];

  cout << max_happiness(N, happiness);
  return 0;
}
