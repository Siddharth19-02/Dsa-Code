class Solution {
public:
    bool isValidPalindrome(string word1, int k) {
        int n = word1.length();
        string word2 = word1;
        reverse(word2.begin(),word2.end());
        int maxLength = 0;
        int dp[n+1][n+1];
        
        dp[0][0] = 0;
        for(int i=1;i<n+1;i++)
        {
            dp[i][0] = 0;
        }
        for(int j=1;j<n+1;j++)
        {
            dp[0][j] = 0;
        }

        for(int i=1;i<n+1;i++)
        {
            for(int j=1;j<n+1;j++)
            {
                if(word1[i-1]==word2[j-1])
                {
                    dp[i][j] = dp[i-1][j-1]+1;
                    maxLength = max(maxLength,dp[i][j]);
                }
                else
                {
                    dp[i][j] = max(dp[i-1][j],dp[i][j-1]);
                }
            }
        }
        
        return (n-maxLength)<=k;
    }
};
