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

bool isVowel(char ch)
{
    ch = tolower(ch);
    if(ch == 'a' || ch == 'e' || ch == 'i' || ch == 'o' || ch == 'u') return true;
    return false;
}
bool checkValid(string &word)
{
    int n = word.size();
    if (word.size() == 0) return false;
    return isVowel(word[0]) && isVowel(word[n-1]);
}
int main()
{
    FASTIO;
    int n ;
        cin >> n ;
        vs words(n);
        vi pref(n,0);
        rep(i,0,n)
        {
            cin >> words[i];
            //check starts and ends with vowel
            int isValid = checkValid(words[i]) ? 1 : 0 ;
            if(i == 0)
            {
                pref[i] = isValid;
            }
            else
            {
                pref[i] = isValid + pref[i-1];
            }
        }
        int q;
        cin >> q;
        while(q--)
        {
            int i , j;
            cin >> i >> j;
            int ans = pref[j];
            if(i > 0) ans -= pref[i-1]; // gets range from j to i words...
            cout << ans << el;
        }
    return 0;
}