class Solution {
public:
    long long countBadPairs(vector<int>& nums) {
        unordered_map<int,int>mp;
        long badPairs = 0;

        for(int i=0;i<nums.size();i++)
        {
            int currDiff = i - nums[i];

            badPairs += i - mp[currDiff];

            mp[currDiff]++;
        }

        return badPairs;
    }
};
