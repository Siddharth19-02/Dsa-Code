class Solution {
public:
    int countVowelPermutation(int n) {
        
        if(n==1)
            return 5;
        
        long dp[n][5];
        
        int ans = 0;
        
        for(int i=0;i<5;i++)
            dp[0][i] = 1;
        
        for(int i=1;i<n;i++)
        {
            dp[i][0] = dp[i-1][1]%1000000007;
            dp[i][1] = (dp[i-1][0] + dp[i-1][2])%1000000007;
            dp[i][2] = (dp[i-1][0] + dp[i-1][1]+ dp[i-1][3] + dp[i-1][4])%1000000007;
            dp[i][3] = (dp[i-1][2] + dp[i-1][4])%1000000007; 
            dp[i][4] = (dp[i-1][0])%1000000007;
        }
        
        for(int i = 0;i<5;i++)
        {
            ans  = (ans + dp[n-1][i])%1000000007;
        }
        return ans;
    }
};
