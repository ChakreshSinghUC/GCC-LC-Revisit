#include<iostream>
#include<vector>
#include<algorithm>

typedef long long ll;

using namespace std;
int n;
bool sortFnc(pair<ll, ll> &p1, pair<ll, ll> &p2)
{
    return p1.second < p2.second;
}
void solve()
{
    cin >> n;
    vector<pair<ll, ll>> movies; 

    for (ll i = 0; i < n; i++)
    {
        ll start, finish;
        cin >> start >> finish;
        movies.push_back({start, finish});
    }

    // Sorting of movies according to their finish time.
    sort(movies.begin(), movies.end(), sortFnc);

    ll timeElapsed = 0, moviesWatched = 0;

    for (ll i = 0; i < n; i++)
    {
        // If the current movie starts after the time
        // elapsed so far, then we can watch it
        if (movies[i].first >= timeElapsed)
        {
            moviesWatched++;
            timeElapsed = movies[i].second;
        }
    }

    // return the total number of movies watched
    cout<< moviesWatched;
    }

    int main()
    {
        cin.tie(0);
        solve();
        return 0;
}