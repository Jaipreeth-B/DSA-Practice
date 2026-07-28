// Problem 0015: Valid Parentheses
// Let's get to work!

#include <bits/stdc++.h>
using namespace std;

// Fast I/O
#define FASTIO ios::sync_with_stdio(false); cin.tie(nullptr); cout.tie(nullptr);

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
class Solution {
public:
    bool isValid(string s) 
    {
        vc a;
        a.reserve(s.size());
        rep(i,0,s.size())
        {
            if(s[i] == '(' || s[i] == '{' || s[i] == '[')
            {
                a.pb(s[i]);
            }
            else
            {
                if(a.size() == 0) return false;
                char ch = a.back();a.popb();
                if((s[i] == ')' && ch == '(')||(s[i] == ']' && ch == '[')||(s[i] == '}' && ch == '{'))
                {
                    
                }
                else
                {
                    return false;
                }
            }
        }

        return a.empty();
    }
};