class Solution {
public:
    int maxDistance(vector<vector<int>>& arrays) {
        
        int small = arrays[0][0];

        int big = arrays[0][arrays[0].size()-1];

        int distance = INT_MIN;

        for(int i=1;i<arrays.size();i++)
        {
            distance = max(distance , max(big - arrays[i][0], arrays[i].back()-small) );
            small = min(small, arrays[i][0]);
            big = max(big, arrays[i].back());
        }

        return distance;

    }
};


// initial way

class Solution {
public:
    int maxDistance(vector<vector<int>>& arrays) {
        
        int firstSmall = arrays[0][0];
        int firstSmallIndex = 0;

        int secondSmall = INT_MAX;
        int secondSmallIndex = -1;

        int firstBig = arrays[0][arrays[0].size()-1];
        int firstBigIndex = 0;

        int secondBig = INT_MIN;
        int secondBigIndex = -1;

        for(int i=1;i<arrays.size();i++)
        {

            int n = arrays[i].size();
            if(arrays[i][0]<=firstSmall)
            {
                secondSmall = firstSmall;
                secondSmallIndex = firstSmallIndex;
                firstSmall = arrays[i][0];
                firstSmallIndex = i;
            }
            else if(arrays[i][0]<secondSmall)
            {
                secondSmall = arrays[i][0];
                secondSmallIndex = i;
            }

            if(arrays[i][n-1]>=firstBig)
            {
                secondBig = firstBig;
                secondBigIndex = firstBigIndex;
                firstBig = arrays[i][n-1];
                firstBigIndex = i;
            }
            else if(arrays[i][n-1]>secondBig)
            {
                secondBig = arrays[i][n-1];
                secondBigIndex = i;
            }
        }


        if(firstSmallIndex != firstBigIndex)
        {
            return abs(firstBig - firstSmall);
        }

        return max(abs(firstBig - secondSmall), abs(secondBig - firstSmall) );

    }
};
