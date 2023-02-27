class Solution {
public:
    int minimumDeleteSum(string s1, string s2) {
        
        int n = s1.length();
        int m = s2.length();
        
        vector<int>dp(m+1,0);
        
        int maxi = 0;
        
        for(int i=1;i<n+1;i++)
        {
            int curr = dp[0];
            for(int j=1;j<m+1;j++)
            {
                int curr2 = dp[j];
                if(s1[i-1] == s2[j-1])
                {
                    dp[j] = curr + s1[i-1];
                    maxi = max(maxi,dp[j]);
                }
                else
                {
                    dp[j] = max(dp[j],dp[j-1]);
                }
                curr =  curr2;
            }
        }
        
        int first = 0, second = 0;
        
        for(int i=0;i<n;i++)
            first += s1[i];
        
        for(int i=0;i<m;i++)
            second += s2[i];
        
        return (first + second - (2*maxi));
        
    }
};
