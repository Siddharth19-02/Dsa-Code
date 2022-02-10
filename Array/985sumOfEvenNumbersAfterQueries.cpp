class Solution {
public:
    vector<int> sumEvenAfterQueries(vector<int>& nums, vector<vector<int>>& queries) {
        
        int sum = 0;
        
        for(auto x : nums)
        {
            if(x%2)
            {
                continue;
            }
            else
                sum += x;
        }
        
        vector<int>result;
        
        for(int i=0;i<queries.size();i++)
        {
            int value = queries[i][0];
            int index = queries[i][1];
            
            value += nums[index];
            
            if(nums[index]%2!=0)
            {
                if(value%2!=0)
                {
                    nums[index] += queries[i][0];
                    result.push_back(sum);
                }
                else
                {
                    sum += value;
                    nums[index] += queries[i][0];
                    result.push_back(sum);
                }
            }
            else
            {
                if(value%2!=0)
                {
                    sum -= nums[index];
                    nums[index] += queries[i][0];
                    result.push_back(sum);
                }
                else
                {
                    int curr = value - nums[index];
                    sum += curr;
                    nums[index] += queries[i][0];
                    result.push_back(sum);
                }
            }
        }
        
        return result;
    }
};
