#include<iostream>
#include<vector>
#include<algorithm>

typedef long long ll;
using namespace std;

ll n,m;

bool sortFnc(pair<ll, ll> &p1, pair<ll, ll> &p2)
{
    return p1.first < p2.first;
}
void solve()
{
   // cout << "enter: ";
    cin >> n >> m;

    vector<pair<ll, ll>> nums;
    //{{2, 0}, {1, 1}, {3, 2}};

    for (ll i = 0; i < n; i++)
    {
        ll num;
        cin >> num;
        nums.push_back({num, i});
   }

   sort(nums.begin(), nums.end(), sortFnc);

   ll l = 0;
   ll r = nums.size() - 1;

   while (l < r)
   {
       int sum = nums[l].first + nums[r].first;

       if (sum == m)
       {
           cout << nums[l].second + 1 << "\t" << nums[r].second + 1;
           return;
       }
       else if (sum < m)
       {
           l++;
       }
       else
       {
           r--;
       }
    }
    cout << "IMPOSSIBLE";
}

int main()
{
  //  cout << "enter: ";
    cin.tie(0);
    solve();
    return 0;
}