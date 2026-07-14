#include <bits/stdc++.h>
using namespace std;
/*int findQ(vector<int> &arr , int n , int a , int b)
{
    auto ub = upper_bound(arr.begin() , arr.end() , b);
    auto lb = lower_bound(arr.begin() , arr.end() , a);
    auto ans = ub-lb ;
    return ans;
}*/
int findA(vector<int> &arr , int n ,int a)
{
    int l = 0 , h = n-1 , loweridx = n;
    while(l <= h)
    {
        int m = l + (h-l)/2;
        if(arr[m] >= a)
        {
            loweridx = m;
            h = m-1;
        }
        else
        {
            l = m+1;
        }
    }
    return loweridx;
}
int findB(vector<int> &arr , int n , int b)
{
    int l = 0 , h = n-1 , upperIdx = n;
    while(l<=h)
    {
        int m = l + (h-l)/2;
        if(arr[m] > b)
        {
            upperIdx = m;
            h = m-1;
        }
        else
        {
            l = m+1;
        }
    }
    return upperIdx;
}
int findQ(vector<int> &arr , int n , int a , int b)
{
    int greater_than_equal_a = findA(arr,n,a);
    int greater_than_b = findB(arr,n,b);
    return greater_than_b - greater_than_equal_a; // their postions
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
        vector<int> arr(n);
        for(int i = 0 ; i < n ; i++)
        {
            cin >> arr[i];
        }
        sort(arr.begin(),arr.end());
        int q;
        cin >> q;
        while(q--)
        {
            int a , b;
            cin >> a >> b;
            int ans = findQ(arr, n , a , b);
            cout << ans << endl;
        }
    }  
    return 0;
}

