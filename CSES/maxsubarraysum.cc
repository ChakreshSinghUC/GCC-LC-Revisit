#include<iostream>
#include <limits.h>
typedef long long ll;
using namespace std;

ll n,m;
void solve()
{
    cin >> n;
    ll max_sum = INT_MIN;
    ll curr_sum = 0;
    for (ll i = 0; i < n; i++)
    {
        ll a;
        cin >> a;
        curr_sum += a;
        max_sum = max(max_sum, curr_sum);
        if (curr_sum<0)
        {
            curr_sum = 0;
        }
    }
    cout << max_sum;
}

int main()
{
  cin.tie(0);
  solve();
  return 0;
}