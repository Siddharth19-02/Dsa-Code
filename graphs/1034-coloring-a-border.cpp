class Solution {
public:
    bool boundaryCheck(vector<vector<int>>& grid,int i,int j,int &currColor)
    {
        if(abs(grid[i][j])==abs(grid[i-1][j]) and abs(grid[i][j])==abs(grid[i+1][j]) and 
          abs(grid[i][j])==abs(grid[i][j-1]) and abs(grid[i][j])==abs(grid[i][j+1]))
            return true;
        return false;
    }
    void dfs(vector<vector<int>>& grid, int i, int j,int &n,int &m,int &currColor)
    {
        if(i<0 or j<0 or i>=n or j>=m or grid[i][j] != currColor)
            return;
        
        grid[i][j] = -currColor;
        dfs(grid,i+1,j,n,m,currColor);
        dfs(grid,i-1,j,n,m,currColor);
        dfs(grid,i,j+1,n,m,currColor);
        dfs(grid,i,j-1,n,m,currColor);
        if(i>0 and j>0 and i<(n-1) and j <(m-1) and boundaryCheck(grid,i,j,currColor))
            grid[i][j] = currColor;
    }
    
    vector<vector<int>> colorBorder(vector<vector<int>>& grid, int row, int col, int color) {
        int currColor = grid[row][col];
        int n = grid.size();
        int m = grid[0].size();
        
        dfs(grid,row,col,n,m,currColor);
        
        for(int i=0;i<n;i++)
        {
            for(int j=0;j<m;j++)
            {
                if(grid[i][j]==(-currColor))
                    grid[i][j] = color;
            }
        }
        
        return grid;
    }
};
