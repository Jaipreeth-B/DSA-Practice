//min heap

#include <bits/stdc++.h>
using namespace std;
int findMinCost(priority_queue<int , vector<int> , greater<int>> &pq)
{
    int totalCost = 0;
    while(!pq.empty())
    {
      int f = 0;
        if(!pq.empty())
        {
            f = pq.top();pq.pop();
        }
        int s = 0;
        if(!pq.empty())
        {
            s = pq.top();pq.pop();
        }
        totalCost = totalCost + (f+s);
        if(!pq.empty())
        pq.push(f+s);
        else
        {
            break;
        }
    }
    return totalCost;
}
int main() {
    /* Enter your code here. Read input from STDIN. Print output to STDOUT */
    int t;
    cin >> t;
    while(t--)
    {
        int n;
        cin >> n;
        priority_queue<int , vector<int> , greater<int>> pq;
        for(int i = 0 ; i < n ; i++)
        {
            int cost;
            cin >> cost;
            pq.push(cost);
        }
        if(n==1) cout << 0 << endl;
        else
        {
            int minCost = findMinCost(pq);
            cout << minCost << endl;
        }
        
    } 
    return 0;
}