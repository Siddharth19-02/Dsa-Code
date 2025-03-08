class Solution {
public:
    int numKLenSubstrNoRepeats(string s, int k) {
        int n = s.size();

        vector<int>count(26,0);
        int start = 0;

        int singleCount = 0;
        int totalCount = 0;

        for(int i=0;i<n;i++)
        {
            count[s[i] - 'a']++;

            if(count[s[i] - 'a'] == 1)
                singleCount++;
            else if(count[s[i] - 'a'] == 2)
                singleCount--;

            if(i - start + 1 == k)
            {
                if(singleCount == k)
                    totalCount++;

                count[s[start] - 'a']--;

                if(count[s[start] - 'a'] == 1)
                    singleCount++;
                else if(count[s[start] - 'a'] == 0)
                    singleCount--;

                start++;
            }
        }

        return totalCount;
    }
};
