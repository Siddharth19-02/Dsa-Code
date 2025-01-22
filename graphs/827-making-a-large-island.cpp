class Solution {

public:
    bool valid(vector<vector<int>>& grid, int x, int y, int n)
    {
        return (x>=0 and y>=0 and x<n and y<n and grid[x][y]!=0);
    }

    int calculateCoodinates(int x, int y, int n)
    {
        return (x*n + y);
    }

    int findParent(int child, vector<int>&parent)
    {
        if(parent[child] == -1)
            return child;

        return parent[child] = findParent(parent[child], parent);
    }

    int groupByRank(int firstx, int firsty, int secondx, int secondy, vector<int>&parent, vector<int>&rank , int n)
    {
        int coodOfFirst = calculateCoodinates(firstx, firsty, n);
        int coodOfSecond = calculateCoodinates(secondx, secondy, n);

        int parentFirst = findParent(coodOfFirst, parent);
        int parentSecond = findParent(coodOfSecond, parent);

        if(parentFirst == parentSecond)
            return 0;

        if(rank[parentFirst] > rank[parentSecond])
        {
            parent[parentSecond] = parentFirst;
            rank[parentFirst] += rank[parentSecond];
            return rank[parentFirst];
        }
        else if(rank[parentFirst] < rank[parentSecond])
        {
            parent[parentFirst] = parentSecond;
            rank[parentSecond] += rank[parentFirst];
            return rank[parentSecond];
        }
        else
        {
            parent[parentSecond] = parentFirst;
            rank[parentFirst] += rank[parentSecond];
            return rank[parentFirst];
        }

        return 0;
    }

    int largestIsland(vector<vector<int>>& grid) {
        int n = grid.size();

        vector<int>parent(n*n,-1);
        vector<int>rank(n*n,1);

        int dx[] = {1,0,-1,0};
        int dy[] = {0,1,0,-1};

        int maxGroup = 1;

        for(int i=0;i<n;i++)
        {
            for(int j=0;j<n;j++)
            {
                if(!grid[i][j])
                    continue;

                for(int k=0;k<4;k++)
                {
                    int x = i + dx[k];
                    int y = j + dy[k];

                    if(valid(grid,x,y,n))
                    {
                        int groupSize = groupByRank(i, j, x, y, parent, rank, n);
                        maxGroup = max(maxGroup, groupSize);
                    }
                }
            }
        }

        for(int i=0;i<n;i++)
        {
            for(int j=0;j<n;j++)
            {
                if(grid[i][j])
                    continue;

                
                unordered_set<int>set;
                int groupSize = 1;

                for(int k=0;k<4;k++)
                {
                    int x = i + dx[k];
                    int y = j + dy[k];

                    if(valid(grid,x,y,n))
                    {
                        int coodinates = calculateCoodinates(x, y, n);
                        int parentOfCoodinate = findParent(coodinates, parent);
                        int size = rank[parentOfCoodinate];

                        if(set.find(parentOfCoodinate) != set.end())
                            continue;

                        groupSize += size;

                        set.insert(parentOfCoodinate);
                    }
                }

                maxGroup = max(maxGroup, groupSize);


            }
        }

        return maxGroup;

    }
};
