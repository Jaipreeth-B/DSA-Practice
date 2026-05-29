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
class Solution {
public:
    bool possible(vi &bloomDay , int mid , int m , int k)
    {
        int cnt = 0 , possibleBouquets = 0 ;
        rep(i,0,sz(bloomDay))
        {
            if(bloomDay[i] <= mid)
            {
                cnt++;
            }
            else
            {
                possibleBouquets += (cnt/k);
                cnt = 0;
                if(possibleBouquets >= m)
                {
                    return true; // end early
                }
            }
        }
        possibleBouquets += (cnt/k);
        return (possibleBouquets >= m) ;
    }
    int minDays(vector<int>& bloomDay, int m, int k) {
        ll ans = 1ll*m*k;
        if(sz(bloomDay) < ans) return -1;
        int minBloom = *min_element(all(bloomDay));
        int maxBloom = *max_element(all(bloomDay));
        int low = minBloom , high = maxBloom;
        while(low <= high)
        {
            int mid = low + (high - low)/2;
            if(possible(bloomDay,mid,m,k))
            {
                ans = mid;
                high = mid - 1;
            }
            else
            {
                low = mid + 1;
            }
        }
        return ans;
    }
};