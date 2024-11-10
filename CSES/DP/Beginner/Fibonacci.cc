#pragma GCC diagnostic push
#pragma GCC diagnostic ignored "-Wc++11-extensions"

#include <algorithm>
#include <iostream>
#include <vector>
#include <chrono>

using namespace std;
using namespace std::chrono;

typedef long long ll;
typedef vector<int> vi;
typedef pair<int, int> pi;

class Solve {
public:
    // Recursive solution (inefficient):
    int fibonacciRecursive(int n)
    {
        /*Time complexity: O(2^n)*/
        // Your solution code here
        if(n<=1) return n;
        return fibonacciRecursive(n - 1) + fibonacciRecursive(n - 2);
    }

    // Dynamic programming (efficient):
    int fibonacci(int n)
    {
        /*Time complexity: O(n)*/
        if(n <= 1)
            return n;
        vi dp(n + 1);
        dp[0] = 0;
        dp[1] = 1;

        for (int i = 2; i<= n; i++)
        {
            dp[i] = dp[i - 1] + dp[i - 2];
        }
        return dp[n];
    }
};

void testFibonacci()
{
    // Add a unit test to assert correctness
    Solve obj;
    assert(obj.fibonacci(0) == 0);
    assert(obj.fibonacci(1) == 1);
    assert(obj.fibonacci(2) == 1);
    assert(obj.fibonacci(3) == 2);
    assert(obj.fibonacci(4) == 3);
    assert(obj.fibonacci(5) == 5);
    assert(obj.fibonacci(6) == 8);
    assert(obj.fibonacci(7) == 13);
    assert(obj.fibonacci(8) == 21);
    assert(obj.fibonacci(9) == 34);
    assert(obj.fibonacci(10) == 55);

    assert(obj.fibonacciRecursive(0) == 0);
    assert(obj.fibonacciRecursive(1) == 1);
    assert(obj.fibonacciRecursive(2) == 1);
    assert(obj.fibonacciRecursive(3) == 2);
    assert(obj.fibonacciRecursive(4) == 3);
    assert(obj.fibonacciRecursive(5) == 5);
    assert(obj.fibonacciRecursive(6) == 8);
    assert(obj.fibonacciRecursive(7) == 13);
    assert(obj.fibonacciRecursive(8) == 21);
    assert(obj.fibonacciRecursive(9) == 34);
    assert(obj.fibonacciRecursive(10) == 55);
}

int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);

    // Run tests to verify correctness
    testFibonacci();

    Solve obj;
    int n = 20;
    // Measure time for dynamic programming solution
    auto start = high_resolution_clock::now();
    int result = obj.fibonacci(n);
    auto stop = high_resolution_clock::now();
    auto duration = duration_cast<microseconds>(stop - start);
    cout << "[Efficient Code] Fibonacci of " << n << " is " << result << endl;
    cout << "Time taken by efficient code: " << duration.count() << " microseconds" << endl;

    // Measure time for recursive solution
    start = high_resolution_clock::now();
    result = obj.fibonacciRecursive(n);
    stop = high_resolution_clock::now();
    duration = duration_cast<microseconds>(stop - start);
    cout << "[Inefficient Code] Fibonacci of " << n << " is " << result << endl;
    cout << "Time taken by inefficient code: " << duration.count() << " microseconds" << endl;

    return 0;
}
#pragma GCC diagnostic pop