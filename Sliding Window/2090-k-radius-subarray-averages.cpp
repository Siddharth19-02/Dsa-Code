class Solution {
public:
    vector<int> getAverages(vector<int>& nums, int k) {
        if (k == 0) 
        {
            return nums;
        }

        int n = nums.size();
        vector<int> avg(n, -1);

        if (2 * k + 1 > n) 
        {
            return avg;
        }

        long long windowSum = 0;
        for (int i = 0; i < (2 * k + 1); i++) 
        {
            windowSum += nums[i];
        }
        avg[k] = windowSum / (2 * k + 1);

        
        for (int i = (2 * k + 1); i < n; i++) 
        {
            windowSum = windowSum - nums[i - (2 * k + 1)] + nums[i];
            avg[i - k] = windowSum / (2 * k + 1);
        }

        return avg;
    }
};
