class Solution {
public:
    bool valid(int x,int y,int n,int m)
    {
        return (x>=0 && y>=0 && x<n && y<m);
    }
    int shortestPath(vector<vector<int>>& grid, int k) {
        
        queue<vector<int> >q;
        q.push({0,0,0,k});
        
        int n = grid. size();
        int m = grid[0].size();
        
        if(grid[n-1][m-1] == 1)
            return -1;
        
        int cood[] = {1,0,-1,0,1};
        
        int check[n][m];
        
        for(int i=0;i<n;i++)
        {
            for(int j=0;j<m;j++)
            {
                check[i][j] = -1;
            }
        }
        
        while(!q.empty())
        {
            vector<int> curr = q.front();
            q.pop();
            
            int x = curr[0];
            int y = curr[1];
            int currk = curr[3];
            
            if(x== n-1 && y == m-1)
                return curr[2];
            
             if(valid(x,y,n,m))
            {
                if(grid[x][y]==1 && currk<=0)
                    continue;

                if(currk<=check[x][y])
                    continue;

                if(grid[x][y]==1)
                    currk -= 1;


                check[x][y] = currk;
                for(int i=0;i<4;i++)
                {
                    int newx = x + cood[i];
                    int newy = y + cood[i+1];

                    q.push({newx,newy,curr[2]+1,currk});
                }
            }
            
            
        }
        return -1;
    }
};
