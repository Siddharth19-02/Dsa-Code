class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        
        if(s.length()==0)
                return 0;
        
        unordered_map<char,int>mp;
        int left=0;
        int max_length =1;
        int i=0;
        for(i=0;i<s.length();i++)
        {
            if(mp.find(s[i])==mp.end())
            {
                mp[s[i]] = i;
            }
            
            else
            {
                if(mp[s[i]]<left)
                {
                    mp[s[i]] = i;
                    continue;
                }
                int length = i - left;
                max_length = max(max_length,length);
                
                left = mp[s[i]]+1;
                mp[s[i]] = i;
            }
            
        }
        int length = i - left;
        max_length = max(max_length,length);
        
        return max_length;        
    }
};
