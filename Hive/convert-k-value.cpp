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
class Sol
{
    private:
        vi heap;
        void heapify(int idx)
        {
            while(idx < sz(heap))
            {
                int maxi = idx;
                int lc = 2*idx +1;
                int rc = 2*idx +2;
                if(lc < sz(heap) && heap[maxi] < heap[lc])
                {
                    maxi = lc;
                }
                if(rc < sz(heap) && heap[maxi] < heap[rc])
                {
                    maxi = rc;
                }
                if(maxi == idx) break;//root itself is min
                swap(heap[idx],heap[maxi]);
                idx = maxi;//update idx
            }
        }
    public:
    void insertEle(int data)
    {
        heap.pb(data);
        int idx = sz(heap)-1;
        int p = (idx -1) /2;
        while(idx > 0 && heap[idx] > heap[p])
        {
            swap(heap[idx],heap[p]);
            idx = p;
            p = (idx-1)/2;//tree bubble swap
        }
    }
    void deleteEle()
    {
        if (heap.empty())
        {
            //cout << "Empty" << el;
            return;
        }
        heap[0] = heap.back();
        heap.popb();
        if(sz(heap) > 0)
        {
            heapify(0);//0 = idx
        }
    }
    int getMax()
    {
        return heap.empty() ? -1 : heap[0];
    }
    int convert(int n , int k)
    {
        int minOperations = 0;
        int curK = k;

        while(curK > 0 && sz(heap) > 0)
        {
            int maxVal = getMax();
            if(maxVal == 0) break;
            curK -= maxVal;
            deleteEle();
            minOperations++;
            int newVal = maxVal/2;
            if(newVal > 0)
            insertEle(newVal);
        }
        return curK <= 0  ? minOperations : -1;
    }
};
int main()
{
    FASTIO;
    int t;
    cin >> t;
    
    while(t--)
    {
        Sol sol;
        int n , k;
        cin >> n >> k;
        rep(i,0,n)
        {
            int data;
            cin >> data;
            sol.insertEle(data);    
        }
        int ans = sol.convert(n,k);
        cout << ans << el;
    }
    return 0;
}