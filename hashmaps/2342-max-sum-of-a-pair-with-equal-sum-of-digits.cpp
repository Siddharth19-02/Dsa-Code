class Solution {
public:
    int digitSum(int num)
    {
        int sum = 0;
        while(num>0)
        {
            sum += num%10;
            num /= 10;
        }

        return sum;
    }
    int maximumSum(vector<int>& nums) {

        vector< int >vec(82,0);
        int maxSum = -1;

        for(int i=0;i<nums.size();i++)
        {
            int sum = digitSum(nums[i]);

            if(vec[sum] and maxSum < nums[i] + vec[sum])
            {
                maxSum = nums[i] + vec[sum];
            }
            
            vec[sum] = (vec[sum]<nums[i])?nums[i]:vec[sum];
        }

        return maxSum;
    }
};
