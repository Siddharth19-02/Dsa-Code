class Solution {
    vector<vector<int>> dirs;
public:
    bool isValid(int x, int y, int n, int m, vector<vector<int>>& maze)
    {
        if(x < 0 || y < 0 || x >= n || y >= m || maze[x][y] == 1) return false;
        return true;
    }
    bool canWeReach(vector<vector<int>>& maze,int x,int y,vector<int>& destination,int n,int m)
    {   
        maze[x][y] = 2;
        
        if(x == destination[0] and y == destination[1])
            return true;
            
        for(int i=0;i<4;i++)
        {
            int newx = x, newy = y;
            while(isValid(newx+dirs[i][0], newy+dirs[i][1], n, m, maze))
            {
                newx += dirs[i][0];
                newy += dirs[i][1];
            }
    
            if(maze[newx][newy] != 2 && canWeReach(maze, newx, newy,destination, n, m)) 
                return true;
        }

        return false;
    }
    
    
    bool hasPath(vector<vector<int>>& maze, vector<int>& start, vector<int>& destination) {
        
        int n = maze.size();
        int m = maze[0].size();
        
        
        dirs = {{0, 1}, {0, -1}, {1, 0}, {-1, 0}};
        
        bool res = canWeReach(maze,start[0],start[1],destination,n,m);
        
        for(int i=0;i<n;i++)
        {
            for(int j=0;j<m;j++)
                cout<<maze[i][j]<<" ";
            cout<<endl;
        }
        
        return res;
    }
};
