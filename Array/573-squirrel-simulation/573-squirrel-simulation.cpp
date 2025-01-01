class Solution {
public:
    int minDistance(int height, int width, vector<int>& tree, vector<int>& squirrel, vector<vector<int>>& nuts) 
    {

        int totalDistance = 0;
        int minDistance = INT_MAX;

        for(int i=0;i<nuts.size();i++)
        {
            int currentDistanceFromSquirrel = abs(nuts[i][0] - squirrel[0]) + abs(nuts[i][1] - squirrel[1]);
            int currentDistanceFromTree =  abs(nuts[i][0] - tree[0]) + abs(nuts[i][1] - tree[1]);

            totalDistance += currentDistanceFromTree;
            minDistance = min(minDistance, currentDistanceFromSquirrel - currentDistanceFromTree);
        }

        return 2*totalDistance + minDistance;
    }
};
