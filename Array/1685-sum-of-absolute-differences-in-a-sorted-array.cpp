class Solution {
public:
    vector<int> getSumAbsoluteDifferences(vector<int>& nums) {
        int n = nums.size();


        int sumBelow = 0;

        int sumTotal = 0;
        for(auto x : nums)
        {
            sumTotal += x;
        }    

        for (int i = 0; i < n; i++) {

            int num = nums[i];

            sumTotal -= num;

            nums[i] = sumTotal - (n - i - 1) * num + i * num - sumBelow;

            sumBelow += num;

        }

        return nums;
    }
};
