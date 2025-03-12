class Solution {
public:
    vector<vector<int>> removeInterval(vector<vector<int>>& intervals, vector<int>& toBeRemoved) {
        vector<vector<int>> result;

        for(int i=0;i<intervals.size();i++)
        {
            int start = intervals[i][0];
            int end = intervals[i][1];

            int startR = toBeRemoved[0];
            int endR = toBeRemoved[1];

            if(start>=endR || startR>=end)
            {
                result.push_back({start , end});
            }
            else
            {
                if(start < startR)
                {
                    result.push_back({start, startR});
                }

                if(end > endR)
                {
                    result.push_back({endR , end});
                }
            }
            
        }

        return result;
    }
};
