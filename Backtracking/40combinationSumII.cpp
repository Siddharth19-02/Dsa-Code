class Solution {
public:
    
    void combination(vector<int> &arr, int target,int index,vector<vector<int>> &ans,vector<int> &curr)
    {
            
        if(target==0)
        {
            ans.push_back(curr);
            return;
        }
        
        if(index==arr.size())
        {
            if(target==0)
            {
                ans.push_back(curr);
            }
            return;
        }
        
       for(int i = index;i<arr.size();i++)
       {
           if(i!=index and arr[i]==arr[i-1])
               continue;
           
           if(target-arr[i]>=0)
           {
               curr.push_back(arr[i]);
               combination(arr,target-arr[i],i+1,ans,curr);
               curr.pop_back();
           }
            
       }
        
    }
    
    vector<vector<int>> combinationSum2(vector<int>& arr, int target) {
        
        int start_index = 0;
        vector<vector<int>> ans;
        vector<int>curr;
        sort(arr.begin(),arr.end());
        
        
        combination(arr,target,start_index,ans,curr);
        
        
        return ans;
        
    }
};
