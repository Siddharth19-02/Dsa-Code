class Solution {
public:
    int max(long long int a , long long int b)
    {
        return (a>=b)?a:b;
    }

    int maxSumAfterOperation(vector<int>& nums) {

        int n = nums.size();
        
        int maxSumWithoutSquare = max(0,nums[0]);
        int maxSumWithSquare = (nums[0] * nums[0]);

        long long int max_sum = max(maxSumWithoutSquare, maxSumWithSquare);

        for(int i=1;i<n;i++)
        {
            maxSumWithSquare = max(nums[i]*nums[i] ,
                    max(maxSumWithoutSquare + nums[i]*nums[i]
                , maxSumWithSquare+nums[i]
                )
            );

            max_sum = max(max_sum, maxSumWithSquare);

            maxSumWithoutSquare = max(0,max(nums[i], nums[i] + maxSumWithoutSquare) );

            max_sum = max(max_sum, maxSumWithoutSquare ); 
        }

        return max_sum;
    }
};
