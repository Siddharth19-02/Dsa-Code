class Solution {
public:
    int maximalNetworkRank(int n, vector<vector<int>>& roads) {
        vector<int> degrees(n, 0);
        vector<vector<int>> adjList(n, vector<int>(n, false));
        for (auto &road : roads) {
          ++degrees[road[0]];
          ++degrees[road[1]];
          adjList[road[0]][road[1]] = true;
          adjList[road[1]][road[0]] = true;
        }
        int ans = 0;
        for (int i = 0; i < n; ++i) {
          for (int j = i + 1; j < n; ++j) {
            ans = max(ans, degrees[i] + degrees[j] - (adjList[i][j] ? 1 : 0));
          }
        }
        return ans;
    }
};
