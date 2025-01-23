class Solution {
public:
    bool valid(vector<vector<char> > &grid, int x, int y,int n ,int m)
    {
        return (x>=0 and y>=0 and x<n and y<m and (grid[x][y] == 'O' || grid[x][y] == '#') );
    }
     int getFood(vector<vector<char> > &grid)
     {
         int n = grid.size();
         int m = grid[0].size();

         pair<int,int> startingPoint;

         for(int i=0;i<n;i++)
         {
             for(int j=0;j<m;j++)
             {
                 if(grid[i][j] == '*')
                 {
                     startingPoint = {i,j};
                 }
             }
         }

         queue<pair<int,int> >q;
         q.push(startingPoint);

         int dx[] = {1,0,-1,0};
         int dy[] = {0,1,0,-1};

         int minDistance = 0;

         while (!q.empty())
         {
             int size = q.size();
             for(int start = 0; start<size;start++)
             {
                 pair<int,int> curr = q.front();
                 q.pop();

                 if(grid[curr.first][curr.second] == '$')
                     return minDistance;

                 for(int i =0;i<4;i++)
                 {
                     int newx = curr.first + dx[i];
                     int newy = curr.second + dy[i];

                     if(valid(grid, newx, newy, n , m))
                     {
                         if(grid[newx][newy] == 'O')
                            grid[newx][newy] = 'X';
                         else
                            grid[newx][newy] = '$';
                        q.push({newx,newy});
                     }
                 }
             }
             minDistance++;
         }

         return -1;
     }
};
