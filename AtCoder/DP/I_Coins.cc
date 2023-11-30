// https://atcoder.jp/contests/dp/tasks
// https://atcoder.jp/contests/dp/tasks/dp_i
// Errichto's solution

#include <iostream>
#include <vector>

using namespace std;

int main() {
  int N;
  cin >> N;

  vector<double> dp(N + 1);
  // d[i] probability that there are i heads so far
  // tails
  dp[0] = 1;
  for (int coin = 0; coin < N; ++coin) {
    double p_heads;
    scanf("%lf", &p_heads);
    for (int i = coin + 1; i >= 0; --i) {
      // probability that there are i heads = probability that there were i-1
      // heads plus 1 head OR there were i heads plus 1 tail
      dp[i] = (i == 0 ? 0 : dp[i - 1] * p_heads) + dp[i] * (1 - p_heads);
    }
  }
  double ans = 0;
  for (int heads = 0; heads <= N; ++heads) {
    int tails = N - heads;
    if (heads > tails) {
      ans += dp[heads];
    }
  }
  printf("%.10lf\n", ans);
}