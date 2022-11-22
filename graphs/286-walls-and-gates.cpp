class Solution {
public:
    bool issafe(int x,int y,vector<vector<int>>& rooms,int n,int m)
    {
        if(x<0 or y<0 or x>=n or y>=m or rooms[x][y] !=INT_MAX)
            return false;
        return true;
    }
    
    void wallsAndGates(vector<vector<int>>& rooms) {
        
        queue<pair<int,int> >q;
        int n = rooms.size();
        int m = rooms[0].size();
        
        for(int i=0;i<n;i++)
        {
            for(int j=0;j<m;j++)
            {
                if(rooms[i][j]==0)
                {
                    q.push({i,j});
                }
            }
        }
        
        while(!q.empty())
        {
            int size = q.size();
            
            for(int j=0;j<size;j++)
            {
                pair<int,int> now = q.front();
                q.pop();
                
                int x = now.first;
                int y = now.second;

                int dx[]={1,-1,0,0};
                int dy[]={0,0,1,-1};

                for(int i=0;i<4;i++)
                {
                    if(issafe(x+dx[i],y+dy[i],rooms,n,m))
                    {
                        rooms[x+dx[i]][y+dy[i]] = rooms[x][y]+1;
                        q.push({x+dx[i],y+dy[i]});
                    }
                }
            }
        }
    }
};
