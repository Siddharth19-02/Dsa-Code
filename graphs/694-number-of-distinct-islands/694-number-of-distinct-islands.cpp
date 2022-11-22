class Solution {
public:
    bool valid(int x,int y,int n,int m,vector<vector<int>>& grid)
    {
        if(x<0 or y<0 or x>=n or y>=m or grid[x][y] == 0)
            return false;
        return true;
    }
    
    void dfs(int x,int y,int n,int m,vector<vector<int>>& grid,string &str)
    {   
        grid[x][y] = 0;
        
        int arr[] = {0,1,0,-1,0};
        
        for(int i=0;i<4;i++)
        {
            int newx = x + arr[i];
            int newy = y + arr[i+1];
            if(valid(newx,newy,n,m,grid))
            {
                str += char('0'+i);
                dfs(newx,newy,n,m,grid,str);
            }
        }
        str += '-';
    }
    
    int numDistinctIslands(vector<vector<int>>& grid) {
        int n = grid.size();
        int m = grid[0].size();
        int count = 0;
        unordered_set<string>s;
        for(int i = 0;i<n;i++)
        {
            for(int j=0;j<m;j++)
            {
                if(grid[i][j] == 1)
                {
                    string str = "-";
                    dfs(i,j,n,m,grid,str);
                    s.insert(str);
                }
            }
        }
        
        return s.size();
    }
};
