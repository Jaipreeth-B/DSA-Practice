class Solution {
public:
    int orangesRotting(vector<vector<int>>& grid) {
        int n = grid.size() , m = grid[0].size();
        //store row,col , timetaken
        queue<pair<pair<int,int>,int>> q;
        //visited same as grid
        vector<vector<int>> vis(n,vector<int>(m));
        int cntFresh = 0;
        for(int i = 0 ; i < n ; i++)
        {
            for(int j = 0 ; j < m ; j++)
            {
                if(grid[i][j] == 2){
                q.push({{i,j},0});
                vis[i][j] = 2;
                }else {
                    vis[i][j] = 0;
                }
                if(grid[i][j] == 1) cntFresh++;
            }
        }
        int tm = 0 , cnt = 0;
        vector<int> deltarow = {-1,0,1,0};
        vector<int> deltacol = {0,1,0,-1}; 
        while(!q.empty())
        {
            int r = q.front().first.first;
            int c = q.front().first.second;
            int t = q.front().second;
            tm = max(tm, t);
            q.pop();
            for(int i = 0 ; i < 4 ; i++)
            {
                int changerow = r + deltarow[i];
                int changecol = c + deltacol[i];
                if(changerow >= 0 && changerow < n && changecol >=0 && changecol < m && vis[changerow][changecol] != 2 && grid[changerow][changecol] == 1)
                {
                    q.push({{changerow,changecol},t+1});
                    vis[changerow][changecol] = 2;
                    cnt++;
                }
            }
        }
        if(cnt != cntFresh) return -1;
        return tm;
    }
};