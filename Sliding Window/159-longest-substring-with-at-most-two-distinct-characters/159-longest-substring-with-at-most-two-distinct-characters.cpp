class Solution {
public:
    int lengthOfLongestSubstringTwoDistinct(string s) {
        int n = s.size();
        int maxLength = 0;
        int right = 0;
        int left = 0;
        unordered_map<char,int>mp;
        
        while(right<n)
        {
            mp[s[right]]++;
            if(mp.size() > 2)
            {
                int length = right - left;
                maxLength = max(maxLength,length);
                while(mp.size()>2)
                {
                    mp[s[left]]--;
                    if(mp[s[left]] == 0)
                        mp.erase(s[left]);
                    left++;
                }
            }
            right++;
        }
        int length = right - left;
        maxLength = max(maxLength,length);
        return maxLength;
    }
};
