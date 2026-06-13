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
    int findLB(vector<int> &arr , int n , int x)
    {
        int low = 0 , high = n-1 , ans = n;
        while(low <= high)
        {
            int mid = (low + high)/2;
            if(arr[mid] >= x)
            {
                //possible
                ans = mid;
                high = mid -1;
            }
            else
            {
                low = mid + 1;
            }
        }
        return ans;
    }
    vector<int> rowAndMaximumOnes(vector<vector<int>>& mat) {
        //just practicing bin search ;) aware that tc is higher than optimal approach.
        int cmax = 0 , v_ind = -1;
        vector<int> ans = {0,0}; 
        for(int i = 0 ; i < mat.size() ; i++)
        {
            sort(mat[i].begin() , mat[i].end());
        }
        for(int i = 0 ; i < mat.size() ; i++)
        {
            int findlowerbound = findLB(mat[i],mat[i].size() , 1);
            int c1s = mat[i].size() - findlowerbound; //lb = idx
            if(c1s > cmax)
            {
                cmax = c1s;
                ans = {i,c1s};
            }
        }
        return ans;
    }
};