bool mycmp(vector<int> &a,vector<int> &b)
{
    if(a[0]==b[0])
        return a[1]>b[1];
    else
        return a[0]<b[0];
}

class Solution {
public:
    int removeCoveredIntervals(vector<vector<int>>& intervals) {
        
        int n = intervals.size();
        
        int count = 1;
        
        sort(intervals.begin(),intervals.end(),mycmp);
        
        int start = intervals[0][0];
        int end = intervals[0][1];
        
        for(int i=1;i<n;i++)
        {
            int currStart = intervals[i][0];
            int currEnd = intervals[i][1];
            
            if(currEnd>=start and currEnd<=end)
                continue;
            else
            {
                start = intervals[i][0];
                end = intervals[i][1];
                count++;
            }
        }
        return count;
    }
};
