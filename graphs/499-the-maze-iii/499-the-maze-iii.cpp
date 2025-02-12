class point {
    public:
    int x;
    int y;
    int distance;
    string path;

    point(int x,int y, int distance, string path)
    {
        this->x = x;
        this->y = y;
        this->distance = distance;
        this->path = path;
    }

};

class Compare {
    public:
       bool operator()(point &a, point &b){
            if(a.distance == b.distance)
                return a.path > b.path;
                
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

    string findShortestWay(vector<vector<int>>& maze, vector<int>& ball, vector<int>& hole)   
    {
        
        int n = maze.size();
        int m = maze[0].size();

        vector< vector<int> >visited(n, vector<int>(m, INT_MAX));
        visited[ball[0]][ball[1]] = 0;

        priority_queue<point , vector<point> ,Compare > pq;

        point p(ball[0], ball[1], 0, "");
        pq.push(p); 

        vector<vector<int>> dirs = {{0, 1}, {0, -1}, {1, 0}, {-1, 0}};
        vector<string>testDirection = {"r", "l", "d", "u"};

        while(!pq.empty())
        {
            auto [x, y, distance, path] = pq.top();
            pq.pop();

            if(x == hole[0] and y == hole[1])
            {
                return path;
            }

            for(int i=0;i<4;i++)
            {
                int newx = x, newy = y, currDistance = 0;
                while(isValid(newx+dirs[i][0], newy+dirs[i][1], n, m, maze))
                {
                    newx += dirs[i][0];
                    newy += dirs[i][1];
                    currDistance++;
                    if(newx == hole[0] and newy == hole[1])
                    {
                        break;
                    }
                }
        
                if(currDistance !=0 and distance + currDistance <= visited[newx][newy])
                {
                    visited[newx][newy] = distance + currDistance;
                    point newPoint(newx,newy,visited[newx][newy], path + testDirection[i]);
                    pq.push(newPoint);
                }
            }

        }

        return "impossible";
    }
};
