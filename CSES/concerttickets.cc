// https://cses.fi/problemset/task/1091
// Problem statement in my words:
// we have an array of positive integers (prices of tickets)
// we have another such array of prices that are announced by customers
// if a customer announces a price Pi that is willing to pay, then he is awarded a ticket whose price is either equal to Pi or closest to Pi.

#include <iostream>
#include <iterator>
#include <set>

using namespace std;

int n,m,h,t;
multiset<int> tickets;

void solve()
{
  cin>>n >> m;
  for(int i = 0; i<n; ++i)
  {
      cin >> h;
      tickets.insert(h);
  }

  for (int i = 0; i < m; ++i)
  {
      cin >> t;
      auto it = tickets.upper_bound(t);
      if (it == tickets.begin())
      {
          cout << -1 << "\n";
      }
      else
      {
          cout << *(--it) << "\n";
          tickets.erase(it);
      }
  }
}

int main()
{
  cin.tie(0);
  solve();
  return 0;
}