class Solution {
public:
    long long min(long long a , long long b)
    {
        return (a<b)?a:b;
    }

    long long max(long long a , long long b)
    {
        return (a>b)?a:b;
    }

    long long gridGame(vector<vector<int>>& grid) {

        int n = grid.size();
        int m = grid[0].size();

        long long leftSum = 0;
        long long rightSum = 0;

        for(int j=0;j<m;j++)
        {
            leftSum += grid[0][j];
        }

        long long mini = LLONG_MAX;
        for(int j=0;j<m;j++)
        {
            leftSum -= grid[0][j];
            mini = min(mini, max(leftSum, rightSum) );
            rightSum += grid[1][j];
        }

        return mini;
    }
};
