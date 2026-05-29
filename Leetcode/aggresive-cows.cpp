#include <bits/stdc++.h>
using namespace std;

// Fast I/O
#define FASTIO ios::sync_with_stdio(false); cin.tie(nullptr); cout.tie(nullptr)

// Type Aliases
#define ll long long
#define ull unsigned long long
#define ld long double
#define pii pair<int,int>
#define pll pair<ll,ll>
#define vi vector<int>
#define vll vector<long long>
#define vvi vector<vector<int>>
#define vvll vector<vector<ll>>
#define vc vector<char>
#define vvc vector<vector<char>>
#define vs vector<string>
#define vvs vector<vector<string>>
#define vb vector<bool>
#define vvb vector<vector<bool>>

// Constants
const int MOD = 1e9 + 7;
const int MOD2 = 998244353;
const int INF = 1e9;
const ll LLINF = 1e18;
const ld EPS = 1e-9;
const ld PI = acos(-1.0);

// Utility Macros
#define stf shrink_to_fit
#define pb push_back
#define popb pop_back
#define mp make_pair
#define fi first
#define se second
#define sz(x) ((int)(x).size())
#define all(x) (x).begin(),(x).end()
#define rall(x) (x).rbegin(),(x).rend()
#define el '\n'

// Loop Macros
#define rep(i,a,b) for (auto i=(a); i<(b); i++)
#define rrep(i,a,b) for (auto i=(a); i>=(b); i--)

bool canPlaceCow(vi &dist , int threshold , int cows)
{
    int cntCows = 1 , lastPlaced = dist[0] , n = sz(dist);
    rep(i,1,n)
    {
        if(dist[i] - lastPlaced >= threshold)
        {
            cntCows++;
            lastPlaced = dist[i];
        }
        if(cntCows == cows) return true; //end early
    }
    return false;
}
int aggresiveCows(int n , vi &dist , int c)
{
    sort(all(dist));
    if(c == 2)
    {
        return dist[n-1] - dist[0];
    }
    int low = 1 , high = dist[n-1] - dist[0];
    while(low <=high)
    {
        int mid = low + (high - low) / 2;

        if(canPlaceCow(dist , mid , c))
        {
            low = mid + 1;
        }
        else
        {
            high = mid -1;
        }
    }
    return high;
}
int main()
{
    FASTIO;
    int t;
    cin >> t;
    while(t--)
    {
        int n , c;
        cin >> n >> c;
        vi dist(n);
        rep(i,0,n)
        {
            cin >> dist[i];
        }
        cout << aggresiveCows(n,dist,c) << el;
    }
}