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
//Using policy based DS
//header files
#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>
using namespace __gnu_pbds;

typedef tree<
pair<int,int>,
null_type,
less<pair<int,int>>,
rb_tree_tag,
tree_order_statistics_node_update>
ordered_set;

void find_anytime_median(vi &a , int n , ordered_set &os)
{
    for(int i = 0 ; i < n ; i++)
    {
        os.insert({a[i],i}); //inserting duplicate values taking adv of (idx always unique)
        //as set can't have dupes we use pair ;)
        int target_idx = i/2; //for median :D
        auto it = os.find_by_order(target_idx);
        cout << it->first << " "; // getting median ;)
    }
}
int main()
{
    FASTIO;
    int t;
    cin >> t;
    while(t--)
    {
        int n;
        cin >> n;
        vi a(n);
        rep(i,0,n) cin >> a[i];

        ordered_set os;

        find_anytime_median(a,n,os);
        cout << el;
    }
    return 0;
}