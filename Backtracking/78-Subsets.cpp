class Solution {
public:
    void subset(vector<int>& nums,vector<vector<int>> &ans,vector<int> &curr,int index,int n)
    {
        ans.push_back(curr);
        if(index==n)
        {
            
            return;
        }
        
        for(int i=index;i<n;i++)
        {
            curr.push_back(nums[i]);
            subset(nums,ans,curr,i+1,n);
            curr.pop_back();
        }
        
    }
    
    vector<vector<int>> subsets(vector<int>& nums) {
         vector<vector<int>> ans;
         vector<int>curr;
        int n = nums.size();
        subset(nums,ans,curr,0,n);
        return ans;
    }
};
