class Solution {
public:
    vector<int> minAvailableDuration(vector<vector<int>>& slots1, vector<vector<int>>& slots2, int duration) {
        
        int n = slots1.size();
        int m = slots2.size();

        sort(slots1.begin(), slots1.end());
        sort(slots2.begin(), slots2.end());

        int i = 0, j = 0;

        while(i<n and j<m)
        {
            int start1 = slots1[i][0];
            int end1 = slots1[i][1];

            int start2 = slots2[j][0];
            int end2 = slots2[j][1];

            int startM = max(start1, start2);
            int endM = min(end1, end2);

            if(endM - startM >= duration)
            {
                return {startM, startM+duration};
            }
            else if(end2>end1)
            {
                i++;
            }
            else
            {
                j++;
            }
        }

        return {};

    }
};
