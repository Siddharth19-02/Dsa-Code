class Solution {
public:
    int nearestExit(vector<vector<char>>& maze, vector<int>& entrance) {
        queue<pair<int,int>> q;

        q.push({entrance [0], entrance[1]});

        int moves=1;
        int rows=maze.size();
        int cols=maze[0].size();

        vector<vector<int>> coodinates={{0,1},{1,0},{0,-1},{-1,0}};
        maze[entrance[0]][entrance[1]]='+';

        while(!q.empty())
        {
            int size=q.size();
            for(int i=0;i<size;i++)
            {
                pair<int,int> curr = q.front();
                q.pop();
                for(int j=0;j<4;j++)
                {
                    int x=curr.first+coodinates[j][0];
                    int y=curr.second+coodinates[j][1];
                    if(x<0 || y<0 || x>=rows || y>=cols || maze[x][y]=='+')
                        continue;

                    if(x==0 || y==0 || x==rows-1 || y==cols-1)
                        return moves;

                    maze[x][y]='+';
                    q.push({x,y});
                }
            }
            moves++;
        }
        return -1;
    }
};
