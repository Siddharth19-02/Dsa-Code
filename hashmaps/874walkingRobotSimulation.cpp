class Solution {
public:
    int robotSim(vector<int>& commands, vector<vector<int>>& obstacles) {
        
        int dx[]={0,1,0,-1};
        int dy[]={1,0,-1,0};
        
         map<pair<int,int>,int> mp;
        
        for(auto x: obstacles)
        {
            mp[{x[0],x[1]}]++;
        }
        
        int x = 0;
        int y = 0;
        
        int dir = 0;
        int curr=0;
        for(int i=0;i<commands.size();i++)
        {
            if(commands[i]>0)
            {
                while(commands[i]--)
                {
                    x = x + dx[dir];
                    y = y+dy[dir];
                    
                    if(mp.find({x,y})!=mp.end())
                    {
                        x = x - dx[dir];
                        y = y-dy[dir];
                        break;
                    }
                }
                int maxi = pow(x,2) + pow(y,2);
                curr = max(maxi,curr);
            }
            else if(commands[i]==-2)
            {
                dir = (dir+3)%4;
            }
            else
            {
                dir  = (dir+1)%4;
            }
        }
        int maxi = pow(x,2) + pow(y,2);
        curr = max(maxi,curr);
        return curr;
    }
};



class Solution {
    // 23:01
    struct comp {
      bool operator()(const pair<int, int>& a, const pair<int, int>& b) const
      {
          return a.first < b.first || (a.first==b.first && a.second < b.second);
      }
    };
    
    void _move(int& l, int& r, int x, int y, int direction)
    {
        switch(direction)
        {
            case 0: l=x; r = y+1;    break;
            case 1: l = x+1; r=y;    break;
            case 2: l=x; r = y-1;    break;
            case 3: l = x-1; r=y;    break;
        }
    }
public:
    int robotSim(vector<int>& commands, vector<vector<int>>& obstacles) {
        set<pair<int, int>, comp> hash;
        int n = obstacles.size();
        for(int i=0;i<n;i++)
        {
            hash.insert(make_pair(obstacles[i][0], obstacles[i][1]));
        }
        
        int x = 0, y = 0;
        int direction = 0;
        // N = 0, E = 1, S = 2, W = 3
        
        int answer = 0;
        
        for(int i=0;i<commands.size();i++)
        {
            if(commands[i]==-1)
            {
                direction++;
                direction%=4;
            }
            else
            if(commands[i]==-2)
            {
                direction--;
                direction = (direction+4)%4;
            }
            else
            {
                int steps = commands[i];
                while(steps--)
                {
                    int l, r;
                    _move(l, r, x, y, direction);
                    if(hash.count(make_pair(l, r)))
                        break;
                    else
                    {
                        x = l;
                        y = r;
                        answer = max(answer, x*x+y*y);
                    }
                }
            }
        }
        
        return answer;
    }
};
