class Solution {
    public:
    int mod = 1000000007;
    int dx[4] = {1,0,-1,0};
    int dy[4] = {0,1,0,-1};

    bool isValid(int i,int j,vector<vector<int>>& grid)
    {
        if(i<0 || i>= grid.size() || j<0 || j>= grid[0].size())
            return false;

        return true; 
    } 

    int dfs(int x,int y,vector<vector<int>>& grid,vector<vector<int>>& dp)
    {
        if(dp[x][y] != -1)
         return dp[x][y];

        int ans = 1;

        for(int i=0;i<4;i++)
        {
            int newx = x + dx[i];
            int newy = y + dy[i];

            if(isValid(newx,newy,grid) && grid[newx][newy] > grid[x][y])
            {
                ans = (ans%mod + dfs(newx,newy,grid,dp)%mod)%mod;
            }
        }

        return dp[x][y]=ans;
    } 

    int countPaths(vector<vector<int>>& grid) 
    {
        
         vector<vector<int>> dp(grid.size(),vector<int>(grid[0].size(),-1));
         long long cnt = 0;

         for(int i=0;i<grid.size();i++)
           for(int j=0;j<grid[0].size();j++)
             cnt = (cnt%mod + dfs(i,j,grid,dp)%mod)%mod;

         return (int)cnt%mod;     
    }
};
