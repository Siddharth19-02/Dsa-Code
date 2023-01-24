class Solution {
public:
    char find(char curr,vector<char> &mp)
    {
        if(mp[curr-'a'] == '0' or mp[curr-'a'] == curr)
        {
            return mp[curr-'a'] = curr;
        }
        return mp[curr-'a'] = find(mp[curr-'a'],mp);
    }
    
    void unionFind(char &a,char &b,vector<char> &mp)
    {
        char curr1 = find(a,mp);
        char curr2 = find(b,mp);
        
        if(curr1 == curr2)
            return;
        
        if(curr1<curr2)
        {
            mp[curr2-'a'] = curr1;
        }
        else
        {
            mp[curr1-'a'] = curr2;
        }
    }
    
    string smallestEquivalentString(string s1, string s2, string baseStr)
    {
        vector<char>mp(26,'0');
        
        for(int i=0;i<s1.size();i++)
        {
            unionFind(s1[i],s2[i],mp);
        }
        
        for(int i=0;i<baseStr.size();i++)
        {
            char curr = find(baseStr[i],mp);
            baseStr[i] = curr;
        }
        return baseStr;
    }
};


