class Solution {
public:
    bool valid(int x, int y, int n, int m, vector< vector<bool> >&visited)
    {
        return x>=0 && y>=0 && x<n && y<m && visited[x][y] == false;
    }

    int maximumMinimumPath(vector<vector<int>>& grid) {
        int n = grid.size();
        int m = grid[0].size();

        vector< vector<bool> >visited(n,vector<bool>(m,false));
        vector< vector<int> >score(n,vector<int>(m,INT_MAX));

        priority_queue< vector<int> >pq;
        pq.push({grid[0][0], 0, 0});

        score[0][0] = grid[0][0];

        int dx[] = {1,0,-1,0};
        int dy[] = {0,1,0,-1};

        while(!pq.empty())
        {
            vector<int> curr = pq.top();
            pq.pop();

            int currScore = curr[0];
            int x = curr[1];
            int y = curr[2];

            if(x == n-1 and y == m-1)
            {
                return currScore;
            }

            visited[x][y] = true;

            for(int i=0;i<4;i++)
            {
                int newx = x + dx[i];
                int newy = y + dy[i];
                if(valid(newx,newy,n,m,visited) )
                {
                    if(score[newx][newy]  > currScore)
                    {
                        score[newx][newy] = min(grid[newx][newy], currScore);
                        pq.push({score[newx][newy], newx, newy});
                    }
                }
            }
        }

        return score[n-1][m-1];
    }
};
