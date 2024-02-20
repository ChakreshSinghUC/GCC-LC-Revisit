#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;
#define ll long long
int main()

{
    ll p, c;
    cin>> p>> c;
    vector<ll> prices(p);
    vector<ll> customers(c);
    for(ll i = 0; i<p; i++)
        cin>>prices[i];
    
    for(ll i = 0; i<c; i++)
        cin>> customers[i];

    sort(prices.begin(), prices.end());
    sort(customers.begin(), customers.end());

    int ticket = 0;
    int customer = 0;

    vector<ll> ans(c, -1);

    while(ticket<p && customer<c){
        if(prices[ticket] > customers[customer])
        {
            ticket++;
        }
        else if()
    }


}