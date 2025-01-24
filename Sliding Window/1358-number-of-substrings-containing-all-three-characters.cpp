class Solution {
public:
    int numberOfSubstrings(string s) {
        
        vector<int>count(3,0);
        int totalCount = 0;
        int uniqueCharsTillNow = 0;

        int start = 0;
        int end = 0;

        while(end< s.size())
        {
            count[s[end]-'a']++;

            if(count[s[end] - 'a'] == 1)
            {
                uniqueCharsTillNow++;
            }

            while(count[0] && count[1] && count[2])
            {
                totalCount += s.size() - end;

                count[s[start]-'a']--;
                start++;
            }

            end++;
        }

        return totalCount;
    }
};
