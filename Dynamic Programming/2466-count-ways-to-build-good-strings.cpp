class Solution {
public:
    int countGoodStrings(int low, int high, int zero, int one) {
        vector<int>dp(high+1,0);
        dp[0] = 1;

        int sum = 0;
        
        for(int i=1;i<=high;i++)
        {
            if(i >= zero)
            {
                dp[i] += dp[i-zero] ;
            }

            if(i >= one)
            {
                dp[i] += dp[i-one];
            }

            dp[i] %= 1000000007;

            if(i>=low)
            {
                sum += dp[i];
                sum %= 1000000007;
            }
        }

        return sum;
    }
};
