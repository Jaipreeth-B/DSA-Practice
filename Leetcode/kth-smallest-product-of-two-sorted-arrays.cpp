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
    ll cntValid(vi &nums1 , vi& nums2 , ll guess)
    {
        int m = sz(nums2);
        ll tc = 0;
        for(ll ele : nums1)
        {
            //1. When X is +ve 
            if(ele > 0)
            {
                int low = 0 , high = m - 1;
                int valid_ind = -1;
                while(low <= high)
                {
                    int mid = low + (high - low) /2 ;
                    if(ele * nums2[mid] <= guess)
                    {
                        //can be ans now search higher end ; need <= 6 , we pick 2 which is yes but 3 is also possible which is in higher space ( right side)
                        valid_ind = mid;
                        low = mid + 1;
                    }
                    else
                    {
                        high = mid - 1;
                    }
                }
                    tc += (valid_ind + 1);
            }
                //2. when ele is -ve
                else if(ele < 0)
                {
                    int l = 0 , r = m - 1;
                    int valid_ind = m;  
                    while (l <= r)
                    {
                        int mid = l + (r-l) / 2;
                        if(ele * nums2[mid] <= guess) // works , try to find more i.e more elements lower ( opposite to positive ones very similar intuition)
                        {
                            valid_ind = mid;
                            r = mid - 1;
                        }
                        else
                        {
                            l = mid + 1;
                        }
                         // vaild idx till end of arr
                    }
                    tc += (m - valid_ind);
                }
                //3. ele is 0
                else
                {
                    if(guess >= 0)
                    {
                        tc += m; //  all counts as guess(+ve or 0) >= 0;
                    }
                }
        }
        return tc;
    }
    long long kthSmallestProduct(vector<int>& nums1, vector<int>& nums2, long long k) {
        //wkt smallest product can get upto 5*1e4 * 1e5 -> 5* 1e9
        if (nums1.size() > nums2.size()) { //ensuring num1 is always small to optimize time.
        return kthSmallestProduct(nums2, nums1, k); 
        }
        ll low = -1e10 , high = 1e10;
        //If the count is >= k: Our guess might be the answer, or the real answer is even smaller. We record this guess and search the lower half.If the count is < k: Our guess is definitely too small. We discard the lower half and search the upper half.
        ll ans = high;
        while(low <= high){
            ll mid = low + (high - low) / 2;
            ll cnt = cntValid(nums1 , nums2 , mid);
            if(cnt >= k){
                ans = mid;
                high = mid - 1;
            }
            else{
                low = mid + 1;
            }
        }
        return ans;
    }
};

//TC - O(N *log M *log R) r is range -1e10 to 1e10 , m is the range of larger array which we perform bs to count valid , and n is the smallest arr out of two