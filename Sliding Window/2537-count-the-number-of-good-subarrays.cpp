class Solution {
public:
    long long countGood(vector<int>& nums, int k) {
        long long count = 0;
        long long pairs = 0;
        int start = 0;
        long long n = nums.size();
        unordered_map<int,int>mp;

        for(int i=0;i<nums.size();i++)
        {
            mp[nums[i]]++;
            pairs += (mp[nums[i]] - 1);

            while(pairs>= k)
            {
                count += (n - i);
                pairs -= (mp[nums[start] ] - 1);
                mp[nums[start]]--;
                start++;
            }
        }

        return count;
    }
};
