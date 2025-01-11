class Solution {
public:
    bool canConstruct(string s, int k) {
        if(s.size() < k)
            return false;
        
        if(s.size() == k)
            return true;

        int odd = 0;
        for(char ch : s)
        {
            odd ^= (1<<(ch-'a'));
        }

        int setBits = __builtin_popcount(odd);

        return (setBits<=k);
    }
};
