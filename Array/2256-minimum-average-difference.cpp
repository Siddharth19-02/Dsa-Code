class Solution {
public:
    int minimumAverageDifference(vector<int>& nums) {
        int index = 0;
        int ans = INT_MAX;
        int n = nums.size();
        long sum = 0;
        
        for(int i=0;i<nums.size();i++)
            sum += nums[i];
        
        long currSum = 0;
        
        for(int i=0;i<n;i++)
        {
            currSum += nums[i];
            sum -= nums[i];
            int curr = abs ( (currSum/(i+1)) - ((n-i-1>0)?sum/(n-i-1):0) );
            if(curr<ans)
            {
                ans = curr;
                index = i;
            }
        }
        return index;
    }
};
