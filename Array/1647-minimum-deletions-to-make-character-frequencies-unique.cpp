class Solution {
public:
    int minDeletions(string s) {
       
        vector<int> freq(26, 0);
        for (char x : s) 
        {
            freq[x - 'a']++;
        }
        
        sort(freq.begin(), freq.end(), greater<int>());
        
        int count = 0;
        int maxCurr = freq[0];
        for (int i = 0; i < 26 && freq[i] > 0; i++) 
        {
            if (freq[i] > maxCurr)
            {
                count += freq[i] - maxCurr;
                freq[i] = maxCurr;
            }
            maxCurr = max(0, freq[i] - 1);
        }
        
        return count;
    }
};
