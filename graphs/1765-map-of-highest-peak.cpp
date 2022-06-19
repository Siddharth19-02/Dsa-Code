class Solution {
public:
    vector<vector<int>> highestPeak(vector<vector<int>>& isWater) {
        int m = isWater.size();

        int n=isWater[0].size();

        vector <int> dirs={0,-1,0,1,0};

        queue <pair<int,int>> q;

        for(int i=0;i<m;i++)
        {
            for(int j=0;j<n;j++)

            {
                if(isWater[i][j]==1)
                {
                    isWater[i][j]=0;
                    q.push({i,j});
                }
                else
                    isWater[i][j]=-1;
            }
        }

        while(!q.empty())
        {
            int s=q.size();

            while(s--)

            {
                auto p=q.front();
                q.pop();
                for(int k=1;k<5;k++)
                {
                    int i=p.first+dirs[k-1];
                    int j=p.second+dirs[k];
                    if(i>=0&&j>=0&&i<m&&j<n&&isWater[i][j]==-1)
                    {
                        q.push({i,j});
                        isWater[i][j]=isWater[p.first][p.second]+1;
                    }
                }
            }
        }

        return isWater;
    }
};
