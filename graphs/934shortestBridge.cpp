class Solution {
    queue<pair<int,int> >q;
    public:
    
    void dfs(vector<vector<int>>& grid,int x,int y,int n,int m)
    {
        if(x<0 or y<0 or x>=n or y>=m or grid[x][y]!=1)
            return;

        grid[x][y] = -1;
        q.push({x,y});

        dfs(grid,x+1,y,n,m);
        dfs(grid,x-1,y,n,m);
        dfs(grid,x,y+1,n,m);
        dfs(grid,x,y-1,n,m);
        return;
    }
    
    int shortestBridge(vector<vector<int>>& grid) {
        
        
        int n = grid.size();
        int m = grid[0].size();
        bool ans = false;
        for(int i=0;i<n;i++)
        {
            for(int j=0;j<m;j++)
            {
                if(grid[i][j]==1)
                {
                    dfs(grid,i,j,n,m);
                    ans = true;
                    break;
                }
            }
            if(ans)
                break;
        }
        
        int min_steps = 0;
        
        while(!q.empty())
        {
            int size = q.size();
            for(int i=0;i<size;i++)
            {
                int x = q.front().first;
                int y = q.front().second;
                q.pop();
                
                int dx[] = {1,-1,0,0};
                int dy[] = {0,0,1,-1};
                
                for(int j=0;j<4;j++)
                {
                    int newx = x+dx[j];
                    int newy = y+dy[j];
                    
                    if(newx<0 or newy<0 or newx>=n or newy>=m or grid[newx][newy]==-1)
                        continue;
                    
                    
                    if(grid[newx][newy]==0)
                    {
                        q.push({newx,newy});
                        grid[newx][newy] = -1;
                    }
                    else
                        return min_steps;
                }
                
            }
            min_steps++;
            
        }
        
        return min_steps;
    }
};
