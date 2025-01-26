class Solution {
public:
    bool isValid(vector<int> &depth, int x, int y, int n, int m) 
    {
        return (x>=0 and y>=0 and x<n and y<m and depth[findCood(x, y,n,m)] > 0);
    }

    int findCood(int x, int y, int n, int m)
    {
        return ((x*m) + y);
    }

    int findParent(int child, vector<int> &parent)
    {
        if(parent[child] == -1)
            return child;

        return parent[child] = findParent(parent[child], parent);
    }

    void findDepth(int coodFirst, int coodSecond, vector<int> &parent, vector<int> &depth, int &numOfComponents)
    {

        int parentFirst = findParent(coodFirst, parent);
        int parentSecond = findParent(coodSecond, parent);

        if(parentFirst == parentSecond)
        {
            return;
        }

        if(depth[parentFirst] > depth[parentSecond])
        {
            depth[parentFirst] += depth[parentSecond];
            parent[parentSecond] = parentFirst;
        }
        else if(depth[parentFirst] < depth[parentSecond])
        {
            depth[parentSecond] += depth[parentFirst];
            parent[parentFirst] = parentSecond;
        }
        else
        {
            depth[parentFirst] += depth[parentSecond];
            parent[parentSecond] = parentFirst;
        }

        numOfComponents--;

    }

    vector<int> numIslands2(int n, int m, vector<vector<int>>& positions) {
        

        vector<int>parent(n*m, -1);
        vector<int>depth(n*m, 0);

        vector<int>result;
        int numOfComponents = 0;

        int dx[] = {0,1,0,-1};
        int dy[] = {1,0,-1,0};

        for(vector<int> &position : positions)
        {
            int x = position[0];
            int y = position[1];

            int coodinate = findCood(x, y, n, m);

            if(depth[coodinate])
            {
                result.push_back(numOfComponents);
                continue;
            }

            depth[coodinate] = 1;
            numOfComponents++;

            for(int i=0;i<4;i++)
            {
                int newx = x + dx[i];
                int newy = y + dy[i];

                if(isValid(depth, newx, newy, n, m))
                {
                    int coodNeighbour = findCood(newx, newy, n, m);

                    findDepth(coodinate, coodNeighbour, parent, depth, numOfComponents);
                }
            }
            
            result.push_back(numOfComponents);
        }

        return result;
    }
};
