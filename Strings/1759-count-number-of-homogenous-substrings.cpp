class Solution {
public:
    int countHomogenous(string s) {
        int count = 1;
        int result = 1;

        for(int i=1;i<s.size();i++)
        {
            if(s[i] == s[i-1])
            {
                count++;
            }
            else
            {
                count = 1;
            }

            result += count;
            result %= (1000000007);
        }

        return result;
    }
};
