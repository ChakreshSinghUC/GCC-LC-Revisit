// https://cses.fi/problemset/task/1074/
#include<iostream>
#include<vector>
#include<algorithm>
#include <limits>

typedef long long ll;

using namespace std;

int main()

{
    ll n, stickLength;

    cin >> n;

    vector<ll> sticks;

    for (ll i = 0; i < n; i++)
    {
        cin >> stickLength;
        sticks.push_back(stickLength);
    }
    //O(NlnN)
    sort(sticks.begin(), sticks.end());

    vector<ll> costs(n, 0);

    ll h0 = sticks[0];
    for(auto s : sticks)
    {
        costs[0] += s - h0;
    }

    ll minCost = costs[0];

    for(ll i = 1; i<n; i++)
    {
        costs[i] = costs[i - 1] - (n - (2 * i)) * (sticks[i] - sticks[i - 1]);
        minCost = min(minCost, costs[i]);
    }
    cout << minCost;
}