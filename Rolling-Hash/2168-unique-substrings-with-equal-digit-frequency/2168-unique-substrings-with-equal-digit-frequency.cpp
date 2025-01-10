class Solution {
public:
    int equalDigitFrequency(string s) {

        int count = 0;
        long long int mod = 10e9;
        unordered_set<long long int>set;

        for(int start=0;start<s.size();start++)
        {
            long long int hash = 0;

            int uniqueChars = 0;
            int maxFreq = 0;

            vector<int>digit(10,0);

            for(int end = start;end<s.size();end++)
            {
                hash = (31*hash + (s[end]-'0' +1) )%mod;

                if(digit[s[end] -'0'] == 0)
                {
                    uniqueChars++;
                }

                maxFreq = max(maxFreq , ++digit[s[end] - '0'] );

                if((maxFreq * uniqueChars == end -start + 1) and set.find(hash) == set.end())
                {
                    set.insert(hash);
                    count++;
                }
            }
        }

        return count;
    }
};

