class Solution {
public:
    bool isInterleave(string s1, string s2, string s3) {
        int n = s1.length();
        int m = s2.length();
        int l = s3.length();
        
        if(n+m!=l)
            return false;
        
        int dp[n+1][m+1];
        dp[0][0] = 1;
        for(int j=1;j<=m;j++)
        {
            if(s2[j-1]==s3[j-1])
            {
                dp[0][j] = dp[0][j-1];
            }
            else
            {
                dp[0][j] = 0;
            }
        }
        
        for(int i=1;i<=n;i++)
        {
            if(s1[i-1]==s3[i-1])
            {
                dp[i][0] = dp[i-1][0];
            }
            else
                dp[i][0] = 0;
        }
        
        for(int i=1;i<=n;i++)
        {
            for(int j=1;j<=m;j++)
            {
                dp[i][j] = 0;
                if(s1[i-1]==s3[i+j-1] and s2[j-1]==s3[i+j-1])
                {
                    dp[i][j] = dp[i-1][j] or dp[i][j-1];
                }
                else if(s1[i-1]==s3[i+j-1])
                {
                    dp[i][j] = dp[i-1][j];
                }
                else if(s2[j-1]==s3[i+j-1])
                {
                    dp[i][j] = dp[i][j-1];
                }
            }
        }
        return dp[n][m];
    }
};
