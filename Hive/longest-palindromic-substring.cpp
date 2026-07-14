#include <bits/stdc++.h>
using namespace std;

// Fast I/O
#define FASTIO ios_base::sync_with_stdio(false); cin.tie(nullptr); cout.tie(nullptr)

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
#define rep(i,a,b) for (int i=(a); i<(b); i++)
#define rrep(i,a,b) for (int i=(a); i>=(b); i--)

int check_expand(string &s , int l , int r)
{
    while(l >= 0 && r < (int)s.size() && s[l] == s[r])
    {
        l--;
        r++;
    }
    return r - l - 1; // the length of the substr
}
int lps(string &s , int n)
{
    int maxlen = 1;
    for(int i = 0 ; i < n ; i++)
    {
        //oddlen
        int olen = check_expand(s , i , i);

        //evenlen
        int elen = check_expand(s,i,i+1);

        maxlen = max({maxlen,olen,elen});
    }
    return maxlen;
}
int main()
{
    FASTIO;
    int t;
    cin >> t;
    while(t--)
    {
        int n;
        string s;
        cin >> n >> s;
        int ans = lps(s,n);
        cout << ans << el;
    }
    return 0;
}