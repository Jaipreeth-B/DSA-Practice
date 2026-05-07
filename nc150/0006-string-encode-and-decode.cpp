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

    string encode(vector<string>& strs) {
        string enc = "";
        for(string &st : strs)
        {
            enc += to_string((int)st.size()) + "#" + st;
        }
        return enc;
    }

    vector<string> decode(string s) {
        int ptr = 0,ln;
        vector<string> ans;
        while(ptr < s.size())
        {
            int t = ptr;
            while(s[t] != '#')
            {
                t++; 
            }
            ln = stoi(s.substr(ptr,t-ptr));
            int start = t+1;//first character of actual string
            ans.push_back(s.substr(start,ln)); //pos,len
            ptr = start+ln;
        }
        return ans;
    }
};

int main()
{
    FASTIO;
    int t;
    cin >> t;
    while(t--)
    {
        Solution sol;
        cout << "Enter no. of strings :";
        int n; cin >> n;
        vector<string> strs (n);
        rep(i,0,n) cin >> strs[i];
        string enc = sol.encode(strs);
        cout << "Encoded String is :" << enc << el;
        vector<string> decAns = sol.decode(enc);
        cout << "Decoded String is :" ;
        for(const string &st : decAns)
        {
            cout << st << " ";
        }
        cout << el;
    }
    return 0;
}