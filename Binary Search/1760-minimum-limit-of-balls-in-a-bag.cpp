class Solution {
public:
    bool isPossible(vector<int>& nums, int maxOperations , int mid)
    {
        long long result = 0;

        for(int i=0;i<nums.size();i++)
        {
            result += ceil(nums[i]/(double)mid) - 1;
        }

        return (result<=maxOperations);
    }

    int minimumSize(vector<int>& nums, int maxOperations) {
        int low = 1;
        int high = *max_element(nums.begin(),nums.end());
        int result = 1;

        while(low <= high)
        {
            int mid = (low + high)/2;

            if(isPossible(nums, maxOperations, mid))
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
