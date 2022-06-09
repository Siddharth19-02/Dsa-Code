class Solution {
public:
    string customSortString(string order, string s) {
        
        string str = "";
        unordered_map<char,string>mp;
        for(int i=0;i<s.length();i++)
        {
            mp[s[i]] += s[i];
        }
        
        for(auto x : order)
        {
            str += mp[x];
            mp.erase(x);
        }
        
        for(auto x : mp)
        {
            str += x.second;
        }
        return str;
    }
};
