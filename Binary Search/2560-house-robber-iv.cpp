class Solution {
public:
    bool isPossible(vector<int>& nums, int k , int mid)
    {
        int result = 0;

        for(int i=0;i<nums.size();i++)
        {
            if(nums[i]<=mid)
            {
                result++;
                i++;
            }
        }

        return (result>=k);
    }

    int minCapability(vector<int>& nums, int k) {
        
        int low = 1;
        int high = *max_element(nums.begin(),nums.end());
        int result = 1;

        while(low <= high)
        {
            int mid = (low + high)/2;

            if(isPossible(nums, k, mid))
            {
                result = mid;
                high = mid - 1;
            }
            else
            {
                low  = mid + 1;
            }
        }

        return result;
    }
};
