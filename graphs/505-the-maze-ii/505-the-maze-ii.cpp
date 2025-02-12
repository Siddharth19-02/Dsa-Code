class point {
    public:
    int x;
    int y;
    int distance;

    point(int x,int y, int distance)
    {
        this->x = x;
        this->y = y;
        this->distance = distance;
    }

};

class Compare {
    public:
       bool operator()(point &a, point &b){
           return a.distance > b.distance;
      }
};

class Solution {
public:
    bool isValid(int x, int y, int n, int m, vector<vector<int>>& maze)
    {
        if(x < 0 || y < 0 || x >= n || y >= m || maze[x][y] == 1) 
            return false;
        return true;
    }

    int shortestDistance(vector<vector<int>>& maze, vector<int>& start, vector<int>& destination) {
        
        int n = maze.size();
        int m = maze[0].size();

        vector< vector<int> >visited(n, vector<int>(m, INT_MAX));
        visited[start[0]][start[1]] = 0;

        priority_queue<point , vector<point> ,Compare > pq;

        point p(start[0], start[1], 0);
        pq.push(p); 

        vector<vector<int>> dirs = {{0, 1}, {0, -1}, {1, 0}, {-1, 0}};


        while(!pq.empty())
        {
            point curr = pq.top();
            pq.pop();

            int x = curr.x;
            int y = curr.y;
            int distance = curr.distance;

            if(x == destination[0] and y == destination[1])
                return distance;

            for(int i=0;i<4;i++)
            {
                int newx = x, newy = y, currDistance = 0;
                while(isValid(newx+dirs[i][0], newy+dirs[i][1], n, m, maze))
                {
                    newx += dirs[i][0];
                    newy += dirs[i][1];
                    currDistance++;
                }
        
                if(currDistance !=0 and distance + currDistance < visited[newx][newy])
                {
                    visited[newx][newy] = distance + currDistance;
                    point newPoint(newx,newy,visited[newx][newy]);
                    pq.push(newPoint);
                }
            }

        }

        return -1;
    }
};
