class Solution {
public:
    int maxResult(vector<int>& nums, int k) {
        
        int n = nums.size();
        
        deque<int>q;
        q.push_front(0);
        
        for(int i=1;i<n;i++)
        {
            if(q.front()<i-k)
                q.pop_front();
            nums[i] = nums[i] + nums[q.front()];
            cout<<nums[i]<<" ";
            while(!q.empty() and nums[q.back()]<=nums[i])
                q.pop_back();
            q.push_back(i);
        }
        return nums[n-1];
    }
};
