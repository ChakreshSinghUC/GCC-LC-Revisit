#include <iostream>

using namespace std;

// Function to calculate the number of ways to climb stairs
int climbStairs(int n) {
    if (n == 0) return 0;
    if (n == 1) return 1;

    int prev1 = 1, prev2 = 1, current;
    for (int i = 2; i <= n; i++) {
        current = prev1 + prev2;
        prev2 = prev1;
        prev1 = current;
    }
    return current;
}

int main() {
    int n;
    cout << "Enter the number of stairs: ";
    // cin >> n;
    n = 10;

    int result = climbStairs(n);
    cout << "Number of ways to climb " << n << " stairs: " << result << endl;
    
    return 0;
}
