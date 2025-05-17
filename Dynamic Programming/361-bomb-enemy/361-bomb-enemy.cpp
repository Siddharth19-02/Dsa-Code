class Solution {
public:
    int maxKilledEnemies(vector<vector<char>>& grid) {
        
        int n = grid.size();
        int m = grid[0].size();
        int maxKills = 0;

        vector<int>columns(m , 0);

        for(int i=0;i<n;i++)
        {
            int rowValue = 0;
            for(int j=0;j<m;j++)
            {
                if(j == 0 or grid[i][j-1] == 'W')
                {
                    rowValue = 0;
                    for(int k = j;k<m;k++)
                    {
                        if(grid[i][k] == 'E')
                            rowValue++;
                        else if(grid[i][k] == 'W')
                            break;
                    }
                }

                if(i == 0 or grid[i-1][j] == 'W')
                {
                    columns[j] = 0;
                    for(int k = i;k<n;k++)
                    {
                        if(grid[k][j] == 'E')
                            columns[j]++;
                        else if(grid[k][j] == 'W')
                            break;
                    }
                }

                if (grid[i][j] == '0')
                    maxKills = max(maxKills, rowValue + columns[j]);
            }
        }

        return maxKills;
    }
};
