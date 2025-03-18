class Solution {
public:
    long long maximumSubarraySum(vector<int>& nums, int k) {
        long long currSum = 0;
        long long maxSum = 0;
        int start = 0;
        unordered_map<int,int>mp;

        for(int i=0;i<nums.size();i++)
        {
            currSum += nums[i];
            mp[nums[i]]++;

            while(mp[nums[i]] >1 || (i-start + 1>k))
            {
                currSum -= nums[start];
                mp[nums[start]]--;
                start++;
            }

            if(i - start + 1 == k)
            {
                maxSum = max(maxSum, currSum);
            }
        }

        return maxSum;
    }
};
