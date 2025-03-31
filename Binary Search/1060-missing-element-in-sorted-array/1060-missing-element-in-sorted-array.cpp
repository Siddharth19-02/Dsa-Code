class Solution {
public:
    int missingElement(vector<int>& nums, int k) {
        int high = nums.size() - 1;
        int low = 0;
        int result = 0;

        while(low<=high)
        {
            int mid = (low + high)/2;

            if(nums[mid] - nums[0] - mid < k)
            {
                result = mid;
                low = mid + 1;
            }
            else
            {
                high = mid - 1;
            }

        }

        return nums[0] + result + k;;
    }
};
