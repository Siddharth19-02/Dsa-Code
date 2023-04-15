class Solution {
public:
    int maxValueOfCoins(vector<vector<int>>& piles, int x) {
        
        int n = piles.size();
        vector<vector<int> >dp(n+1,vector<int>(x+1,0));
        
        for(int i=1;i<n+1;i++)
        {
            for(int j=1;j<x+1;j++)
            {
                int sum = 0;
                int low = min((int)piles[i-1].size(),j);
                for(int k=0;k<low;k++)
                {
                    sum += piles[i-1][k];
                    dp[i][j] = max(dp[i][j],sum+dp[i-1][j-k-1]);
                }
                dp[i][j] = max(dp[i][j],dp[i-1][j]);
            }
        }
       
        return dp[n][x];
    }
};
