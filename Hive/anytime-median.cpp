/*
Anytime Median bookmark_borderGiven an integer array, print the median for the sub-array 0 to i, for every i, 0 <= i <= N-1.

Input Format
The first line of input contains T - the number of test cases. It's followed by 2T lines - the first line contains N - the size of the array. The second line contains N integers - the elements of the array.

Output Format
For each test case, print the median for the sub-array 0 to i, for every i, separated by space. Print a new line between the output of different test cases. Note that in the case of even length sub-array, print the smaller element as the median.
*/
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

void findAnytimeMedian(vi &a , int n)
{
    priority_queue<int>max_heap;
    priority_queue<int , vector<int> , greater<int>> min_heap;

    for(int i = 0 ; i < n ; i++)
    {
        if(max_heap.empty() || a[i] <= max_heap.top()) // insert such that max heap ele <= min heap ele
        {
            max_heap.push(a[i]);
        }
        else
        {
            min_heap.push(a[i]);
        }
        if(max_heap.size() > min_heap.size()+1) // balance heaps
        {
            int x = max_heap.top();
            max_heap.pop();
            min_heap.push(x);
        }
        if(min_heap.size() > max_heap.size())
        {
            int x = min_heap.top();
            min_heap.pop();
            max_heap.push(x);
        }
        cout << max_heap.top() << " ";
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
        findAnytimeMedian(a , n);
        cout << el;
    }
    return 0;
}