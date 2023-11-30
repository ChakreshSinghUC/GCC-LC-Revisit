// https://atcoder.jp/contests/dp/tasks
// https://atcoder.jp/contests/dp/tasks/dp_d

#include <iostream>
#include <limits>
#include <vector>

#define ll long long

using namespace std;

long long dp[101][100005];

ll knapsack(ll w, ll n, vector<vector<ll>> items) {
  if (n == 0)
    return 0;
  if (w <= 0)
    return 0;

  if (dp[n][w] != -1)
    return dp[n][w];
  ll op1 = (w - items[n][0] >= 0)
               ? (items[n][1] + knapsack(w - items[n][0], n - 1, items))
               : INT_MIN;
  ll op2 = knapsack(w, n - 1, items);
  return dp[n][w] = max(op1, op2);
}

int main() {
  ll N, W;
  cin >> N >> W;
  vector<vector<ll>> items(N + 1, vector<ll>(2));
  for (int i = 1; i <= N; i++) {
    cin >> items[i][0] >> items[i][1];
  }
  memset(dp, -1, sizeof(dp));
  cout << knapsack(W, N, items) << endl;
}