class Solution {
public:
    int findParent(vector<int>&parent, int child)
    {
        if(parent[child] == -1)
            return child;
        
        return parent[child] = findParent(parent, parent[child]);
    }

    bool calculateDepth(vector<int>&parent, vector<int>&depth, int x, int y)
    {
        int parentX = findParent(parent, x);
        int parentY = findParent(parent, y);

        if(parentX == parentY)
            return false;

        if(depth[x] > depth[y])
        {
            parent[parentY] = parentX;
            depth[parentX] += depth[parentY];
        }
        else if(depth[x] < depth[y])
        {
            parent[parentX] = parentY;
            depth[parentY] += depth[parentX];
        }
        else
        {
            parent[parentY] = parentX;
            depth[parentX] += depth[parentY];
        }

        return true;
    }

    int earliestAcq(vector<vector<int>>& logs, int n) {

        sort(logs.begin(), logs.end());

        vector<int>parent(n , -1);
        vector<int>depth(n, 1);

        int result = -1;

        for(auto log : logs)
        {
            bool flag = calculateDepth(parent, depth, log[1], log[2]);
            result = (flag)?log[0]:result;
        }

        int count = 0;
        for(int i = 0;i<n;i++)
        {
            if(parent[i] == -1)
                count++;
        }

        if(count>1)
            return -1;

        return result;
    }
};
