class Solution {
public:
    bool valid(vector<vector<int>>& grid,int x,int y,int n, int m)
    {
        if(x<0 or y<0 or x>=n or y>=m or grid[x][y] == -1)
            return false;
        return true;
    }

    long long sumRemoteness(vector<vector<int>>& grid) {
        
        int n = grid.size();
        int m = grid[0].size();

        long long total = 0;
        long long sum = 0;

        queue<pair<int,int> >q;

        for(int i=0;i<n;i++)
        {
            for(int j=0;j<m;j++)
            {
                if(grid[i][j] != -1)
                {
                    sum += grid[i][j];
                    q.push({i,j});
                }
            }
        }

        int dx[] = {1,0,-1,0};
        int dy[] = {0,1,0,-1};

        while(!q.empty())
        {
            pair<int,int> curr = q.front();
            q.pop();

            int x = curr.first;
            int y = curr.second;

            if(grid[x][y] == -1)
            {
                continue;
            }

            queue<pair<int,int> >subPart;
            subPart.push({x,y});

            long long currSum = sum - grid[x][y];
            int currElements = 1;
            grid[x][y] = -1;

            while(!subPart.empty())
            {
                pair<int,int> curr2 = subPart.front();
                subPart.pop();
    
                int currx = curr2.first;
                int curry = curr2.second;

                for(int i=0;i<4;i++)
                {
                    int newx = currx + dx[i];
                    int newy = curry + dy[i];

                    if(valid(grid,newx,newy,n,m))
                    {
                        currElements++;
                        currSum -= grid[newx][newy];
                        grid[newx][newy] = -1;

                        subPart.push({newx,newy});
                    }
                }
            }

            total += (currSum*currElements);
        }

        return total;
    }

};
