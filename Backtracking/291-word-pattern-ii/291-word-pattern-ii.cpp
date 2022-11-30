class Solution {
public:
    bool isPossible(string &pattern,string &s,unordered_map<char,string> &mp,int i,int j,unordered_set<string> &us)
    {
        if(i == pattern.size() and j == s.size())
            return true;
        
        if((i == pattern.size() and j != s.size()) || (i != pattern.size() and j == s.size()) )
            return false;
        
        if(mp.find(pattern[i]) !=mp.end() )
        {
            string curr = mp[pattern[i]];
            int k = 0;
            while(k<curr.size() and j<s.size())
            {
                if(curr[k]!=s[j])
                {
                    return false;
                }
                k++;
                j++;
            }
            return isPossible(pattern,s,mp,i+1,j,us);
        }
        
        string curr = "";
        while(j<s.size())
        {
            curr += s[j];
            if(us.find(curr) == us.end())
            {
                us.insert(curr);
                mp[pattern[i]] = curr;
                if(isPossible(pattern,s,mp,i+1,j+1,us))
                    return true;
                us.erase(curr);
            }
            j++;
        }
        mp.erase(pattern[i]);
        
        return false;
    }
    
    bool wordPatternMatch(string pattern, string s) {
        
        unordered_map<char,string>mp;
        unordered_set<string>us;
        int i = 0;
        int j = 0;
        
        return isPossible(pattern,s,mp,i,j,us);
        
    }
};
