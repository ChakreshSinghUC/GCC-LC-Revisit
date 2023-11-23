// https://atcoder.jp/contests/dp/tasks
// https://atcoder.jp/contests/dp/tasks/dp_a
#include <iostream>
#include <math.h>
#include <vector>
#define INF 1e9 + 5
using namespace std;

int min_cost_N(int N, vector<int> heights) {
  vector<int> min_cost(N, INF);
  min_cost[0] = 0;

  for (int i = 0; i < N; ++i) {
    for (int j : {i + 1, i + 2}) {
      if (j < N)
        min_cost[j] =
            min(min_cost[j], min_cost[i] + abs(heights[j] - heights[i]));
    }
  }

  return min_cost[N - 1];
}

int main() {
  int N;

  cin >> N;
  vector<int> heights(N, 0);

  for (int i = 0; i < N; i++) {
    cin >> heights[i];
  }

  cout << min_cost_N(N, heights);
}