class Solution {
public:
    void dfs(vector<vector<int>>& grid,int x,int y,int n,int m,int &count)
    {
        if(x<0 or y<0 or x>=n or y>=m or grid[x][y]==0)
            return;
        
        count++;
        grid[x][y] = 0;
        
        dfs(grid,x+1,y,n,m,count);
        dfs(grid,x-1,y,n,m,count);
        dfs(grid,x,y+1,n,m,count);
        dfs(grid,x,y-1,n,m,count);
    }
    
    int maxAreaOfIsland(vector<vector<int>>& grid) {
        
        int n = grid.size();
        int m = grid[0].size();
        
        int max_area = 0;
        
        for(int i=0;i<n;i++)
        {
            for(int j=0;j<m;j++)
            {
                if(grid[i][j]==1)
                {
                    int count = 0;
                    dfs(grid,i,j,n,m,count);
                    max_area = max(max_area,count);
                }
            }
        }
        return max_area;
    }
};
