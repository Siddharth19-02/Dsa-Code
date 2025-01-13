class Solution {
public:
    int minimumLength(string s) {
        int result = s.size();
        vector<int>freq(26,0);

        for(char ch : s)
        {
            freq[ch-'a']++;
        }

        for(int i=0;i<26;i++)
        {
            if(freq[i]>2)
                result -= (2*((freq[i]-1)/2) );
        }

        return result;
    }
};
