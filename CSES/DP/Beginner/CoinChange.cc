#pragma GCC diagnostic push
#pragma GCC diagnostic ignored "-Wc++11-extensions" 

#include <iostream>
#include <vector>
#include <algorithm>
#include <climits>

using namespace std;

int minCoins(vector<int>& coins, int amount) {
    vector<int> dp(amount + 1, INT_MAX);
    dp[0] = 0;

    for (int i = 1; i <= amount; ++i) {
        for (int coin : coins) {
            if (i - coin >= 0 && dp[i - coin] != INT_MAX) {
                dp[i] = min(dp[i], dp[i - coin] + 1);
            }
        }
    }

    return dp[amount] == INT_MAX ? -1 : dp[amount];
}

int main() {
    int n, amount;
    cout << "Enter the number of coin denominations: ";
    cin >> n;
    vector<int> coins(n);
    cout << "Enter the coin denominations: ";
    for (int i = 0; i < n; ++i) {
        cin >> coins[i];
    }
    cout << "Enter the amount: ";
    cin >> amount;

    int result = minCoins(coins, amount);
    if (result == -1) {
        cout << "It is not possible to make the amount with the given coin denominations." << endl;
    } else {
        cout << "The minimum number of coins needed: " << result << endl;
    }

    return 0;
}