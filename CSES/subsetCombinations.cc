#pragma GCC diagnostic push
#pragma GCC diagnostic ignored "-Wc++11-extensions"

#include <algorithm>
#include <iostream>
#include <vector>

using namespace std;

typedef long long ll;
typedef vector<int> vi;
typedef pair<int, int> pi;

int n = 3;
vi subset;

class solve
{
public:
    void search(int k)
    {
        if (k > n)
        {
            // process
            cout << "{";
            for (size_t i = 0; i < subset.size(); ++i)
            {
                cout << subset[i];
                if (i < subset.size() - 1)
                {
                    cout << " ";
                }
            }
            cout << "} \n";
        }
        else
        {
            // include k in the subset
            subset.push_back(k);
            search(k + 1);
            subset.pop_back();
            // exclude k from the subset
            search(k + 1);
        }
    }
};
int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);
    solve obj;
    obj.search(1);
}

/*Time complexity: O(2^n)*/