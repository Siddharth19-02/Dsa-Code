class Solution {
public:
    vector<vector<int>> dirs = {{0, 1}, {0, -1}, {1, 0}, {-1, 0}};

    int minCost(vector<vector<int>>& grid) {
        int n = grid.size(), m = grid[0].size();

        priority_queue<vector<int>, vector<vector<int>>, greater<>> pq;
        pq.push({0, 0, 0});

        vector<vector<int>> minCost(n, vector<int>(m, INT_MAX));
        vector<vector<int>> visited(n, vector<int>(m, false));
        minCost[0][0] = 0;

        while (!pq.empty()) 
        {
            auto curr = pq.top();
            pq.pop();

            int cost = curr[0], row = curr[1], col = curr[2];

            if (row == n-1 && col == m-1) 
                return minCost[row][col];

            if(visited[row][col])
                continue;

            visited[row][col] = true;

            for (int dir = 0; dir < 4; dir++) 
            {
                int x = row + dirs[dir][0];
                int y = col + dirs[dir][1];

                if (x >= 0 && x < n && y >= 0 &&y < m) 
                {
                    int newCost = cost + (dir != (grid[row][col] - 1) ? 1 : 0);

                    if (minCost[x][y] > newCost) 
                    {
                        minCost[x][y] = newCost;
                        pq.push({newCost, x, y});
                    }
                }
            }
        }

        return minCost[n - 1][m - 1];
    }
};
