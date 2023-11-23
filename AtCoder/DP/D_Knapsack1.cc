// https://atcoder.jp/contests/dp/tasks
// https://atcoder.jp/contests/dp/tasks/dp_d
#include <iostream>
#include <math.h>
#include <vector>

using namespace std;
int knapsack(int N, int W, vector<vector<int>> items) {
  int ans = INT_MIN;
  return ans;
}

int main() {
  int N, W;
  cin >> N >> W;
  vector<vector<int>> items(N, vector<int>(2));
  for (int i = 0; i < N; i++) {
    cin >> items[i][0] >> items[i][1];
  }
  cout << knapsack(N, W, items);
}