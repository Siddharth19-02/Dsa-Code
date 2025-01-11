class Solution {
public:
    bool canConstruct(string s, int k) {
        if(s.size() < k)
            return false;
        
        if(s.size() == k)
            return true;

        unordered_map<char,int>mp;

        for(char ch : s)
        {
            mp[ch]++;
        }

        int odd = 0;

        for(const auto &[key,value] : mp)
        {
            if(value%2 != 0)
                odd++;
        }

        return (odd<=k);
    }
};
