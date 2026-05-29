class Solution {
public:
    vector<int> findPeakGrid(vector<vector<int>>& mat) {
        int n = mat.size() , m = mat[0].size();
        int low = 0 , high = m-1;
        while(low <= high)
        {
            int mid = (low + high) / 2;
            int row = 0;
            //int maxRow = 0;
            for (int i = 1; i < n; ++i) {
                if (mat[i][mid] > mat[row][mid]) {
                    row = i;
                }
            }
            int val = mat[row][mid];
            int left = mid - 1 >= 0 ? mat[row][mid-1] : -1 ;
            int right = mid + 1 < m ? mat[row][mid + 1] : -1 ;
            if(val > left && val > right) return {row,mid};
            else if(val < left) high = mid - 1; // eliminate right
            else low = mid + 1;
            
        }
        return {-1,-1};
    }
};