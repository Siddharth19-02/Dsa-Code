class Solution {
public:
    bool wordBreak(string s, vector<string>& wordDict) {
        
        unordered_set<string>st(wordDict.begin(),wordDict.end());
        int n = s.length();
        vector<int>dp(n,0);
        
        dp[0] = 0;
        
        for(int i=0;i<n;i++)
        {
            string curr = s.substr(0,i+1);
            if(st.find(curr)!=st.end())
            {
                dp[i] = 1;
            }
            if(dp[i])
            {
                for(int j=i+1;j<n;j++)
                {
                    string now = s.substr(i+1,j-i);
                    if(st.find(now)!=st.end())
                        dp[j] = true;
                }
            }
        }
        
        return dp[n-1];
    }
};
