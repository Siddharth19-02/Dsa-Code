class Solution {
public:
    vector<int> distinctNumbers(vector<int>& nums, int k) {
        
        int count[100001] = {};
        int ans= 0;
        vector<int> res;

        for (int i = 0; i < nums.size(); ++i) 
        {
            ans += ++count[nums[i]] == 1;
            
            if (i >= k)
            {
                ans -= --count[nums[i - k]] == 0;
            }
            
            if (i + 1 >= k)
            {
                res.push_back(ans);
            }
        }

        return res;
    }
};
