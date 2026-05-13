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
//  HASH AND SORT
class Solution {
public:
    vector<int> topKFrequent(vector<int>& nums, int k) {
        unordered_map<int,int> freq;
        vector<int> ans;
        for(const auto& ele : nums)
        {
            freq[ele]++;
        }
        vector<pair<int,int>> v(freq.begin() , freq.end());
        sort(v.begin() , v.end() , 
        [](const pair<int,int>& a ,const pair<int,int> &b)
        {
            return a.second > b.second;
        });
        for(int i = 0 ; i < k ; i++)
        {
            ans.push_back(v[i].first);
        }
        return ans;
    }
};
//MAX HEAP / MAX PRIORITY
class Solution {
public:
    vector<int> topKFrequent(vector<int>& nums, int k) {
        vector<int> ans;
        using P = pair<int,int>; //template
        priority_queue<P , vector<P> , greater<P>> pq; // min heap
        unordered_map<int,int> mp;
        for(auto& ele : nums)
        {
            mp[ele]++;
        }
        for(auto &p : mp)
        {
            pq.push({p.second , p.first}); //ordered by freq not number
            if((int)pq.size() > k)
            {
                pq.pop();
            }
        }
        ans.reserve(k);
        while(!pq.empty())
        {
            ans.push_back(pq.top().second);
            pq.pop();
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
        
    }
    return 0;
}