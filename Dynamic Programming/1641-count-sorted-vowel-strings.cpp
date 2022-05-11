class Solution {
public:
    int countVowelStrings(int n) {
        int dp[6];
        
        for(int i=0;i<6;i++)
            dp[i] = i;
        
        
        
        for(int i=2;i<n+1;i++)
        {
            for(int j=1;j<6;j++)
            {
                dp[j] += dp[j-1];
            }
        }
        return dp[5];
    }
};
