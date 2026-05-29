class Solution{
public:
    int countSmallEq(vector<vector<int>> &mat , int n , int m , int mid)
    {
        int cnt = 0 ;
        for(int i = 0 ; i < n ; i++)
        {
            cnt += upper_bound(mat[i].begin() , mat[i].end() , mid) - mat[i].begin();
        }
        return cnt;
        
    }
    int findMedian(vector<vector<int>> &mat) {
        // code here
        int low = INT_MAX , high = INT_MIN;
        //given rowwise sorted 
        int n = mat.size() , m = mat[0].size();
        for(int i = 0 ; i < n ; i++)
        {
            low = min(low , mat[i][0]);
            high = max(high , mat[i][m-1]);
        }
        int req = (n*m)/2;
        while(low <= high)
        {
            int mid = (low + high) / 2;
            int smaller_Equal = countSmallEq(mat , n , m , mid);
            if(smaller_Equal <= req) low = mid + 1;
            else high = mid - 1;
        }
        return low;
    }
};