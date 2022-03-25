bool compare(vector<int>&a,vector<int>&b)
{
    int diff = abs(a[0]-a[1]);
    int diff2 = abs(b[0]-b[1]);
    
    return diff>diff2;
}

class Solution {
public:
    int twoCitySchedCost(vector<vector<int>>& costs) {
        int n = costs.size();
        
        sort(costs.begin(),costs.end(),compare);
        
        int totalCost = 0;
        
        int left = 0;
        int right = 0;
        
        for(int i=0;i<n;i++)
        {
            if(costs[i][0]>costs[i][1])
            {
                if(right<n/2)
                {
                    totalCost += costs[i][1];
                    right++;
                }
                else
                {
                    totalCost += costs[i][0];
                    left++;
                }
            }
            else
            {
                if(left<n/2)
                {
                    totalCost += costs[i][0];
                    left++;
                }
                else
                {
                    totalCost += costs[i][1];
                    right++;
                }
            }
        }
        
        return totalCost;
    }
};
