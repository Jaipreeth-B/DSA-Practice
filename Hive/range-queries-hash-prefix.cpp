#include <bits/stdc++.h>
using namespace std;

int solve(vector<int> &pref , int a, int b)
{
    if(a == 0) return pref[b];
    return pref[b] - pref[a-1];
}
int main() {
    /* Enter your code here. Read input from STDIN. Print output to STDOUT */ 
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    int t;
    cin >> t;
    while(t--)
    {
        int n  , k;
        cin >> n >> k;
        vector<int> pref(k+1,0); // pref array idx = actual number count
        for(int i = 0 ; i < n ; i++)
        {
            int x;
            cin >> x;
            //store count of x
            pref[x]++;
        }
        //need : count of integers less than x
        for(int i = 1 ; i <= k ; i++)
        {
            pref[i] = pref[i-1] + pref[i]; 
        }
        int q;
        cin >> q;
        while(q--)
        {
            int a, b;
            cin >> a >> b;
            int integers_in_range = solve(pref , a , b);
            cout << integers_in_range << endl;
        }
    }  
    return 0;
}