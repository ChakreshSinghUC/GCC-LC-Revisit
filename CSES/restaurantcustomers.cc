// https://cses.fi/problemset/task/1619

#include<iostream> 
#include<vector>
#include<algorithm>
using namespace std;

long long n;
void solve()
{
  cin>>n;
  vector<pair<long long, long long>> times;
  for (long long i = 0; i < n; i++)
  {
      long long start, end;
      cin >> start >> end;
      times.push_back({start, 1});
      times.push_back({end + 1, -1});
  }

  sort(times.begin(), times.end());

  long long curr = 0;
  long long at = 0;

  vector<long long> ppl_change(2 * n);

  for (long long i = 0; i< 2*n; i++)
  {
    if(i==0){
      times[i].first = 0;
    } else if(times[i].first > curr)
    {
      at++;
      curr == times[i].first;
    }
    ppl_change[at + 1] = times[i].second;
  }

  vector<long long> ppl_amt(2 * n + 1);
  for (long long i = 1; i < 2 * n + 1; i++)
  {
    ppl_amt[i] = ppl_change[i - 1] + ppl_amt[i - 1];
  }

  // Our answer is just the maximum of the prefix sum array
  long long max_ppl = 0;
  for (long long i = 0; i < 2 * n + 1; i++)
  {
    max_ppl = max(max_ppl, ppl_amt[i]);
  }

  cout << max_ppl << endl;
}

int main()
{
  cin.tie(0);
  solve();
  return 0;
}