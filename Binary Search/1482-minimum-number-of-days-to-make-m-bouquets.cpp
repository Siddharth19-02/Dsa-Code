class Solution {
public:
    bool valid(vector<int>& bloomDay, int m, int k,int mid)
    {
        int adj = 0;
        for(int i=0;i<bloomDay.size();i++)
        {
            if(bloomDay[i]<=mid)
                adj++;
            else
                adj=0;
            
            if(adj==k)
            {
                 m--;
                adj=0;
            }
        }
        return (m<=0);
    }
    
    int minDays(vector<int>& bloomDay, int m, int k) {
        int n = bloomDay.size();
        
        if(m*k>n)
            return -1;
        
        int low = 1;
        int high= 1000000000;
        int ans = -1;
        
        while(low<=high)
        {
            int mid = high - (high-low)/2;
            if(valid(bloomDay,m,k,mid))
            {
                ans = mid;
                high = mid-1;
            }
            else
                low = mid + 1;
        }
        return ans;
    }
};
