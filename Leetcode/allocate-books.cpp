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

ll f(vll &books , ll pgs)
{
    ll stud = 1 , pgsPerStud = 0;
    rep(i,0,sz(books))
    {
        if(pgsPerStud+books[i] > pgs)
        {
            stud++;
            pgsPerStud = books[i];
        }
        else
        {
            pgsPerStud += books[i];
        }
    }
    return stud;
}
long long allocateBooks(vector<long long>& books, ll N, ll M) 
{
    if(M > N) return -1;
    ll low = 0;
    ll high = 0;
    ll ans = -1;
    rep(i,0,N)
    {
        low = max(low , books[i]);
        high+= books[i];
    }
    while(low <= high)
    {
        ll mid = low + (high - low)/2;
        if(f(books , mid ) > M)
        {
            low = mid + 1;
            //need more students; > M → not enough capacity → mid too small → increase low
        }
        else
        {
            //feasible , so we store and try to decrease pgs
            ans = mid;
            high = mid - 1;
        }
    }
    return ans ; // or return ans
}