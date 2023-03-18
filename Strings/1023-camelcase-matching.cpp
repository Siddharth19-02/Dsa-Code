class Solution {
public:
    vector<bool> camelMatch(vector<string>& queries, string pattern) {
        
        int n = queries.size();
        int m = pattern.size();
        vector<bool>ans(n,false);
        
        for(int k=0;k<n;k++)
        {
            int j = 0 ;
            bool flag = true;
            for(int i=0;i<queries[k].size();i++)
            {
                if(j<m && queries[k][i] == pattern[j])
                {
                    j++;
                }
                else if(queries[k][i]>='A' and queries[k][i]<='Z')
                {
                    flag = false;
                    break;
                }
            }
            if(j == m and flag)
                ans[k] = true;
        }
        
        return ans;
    }
};
