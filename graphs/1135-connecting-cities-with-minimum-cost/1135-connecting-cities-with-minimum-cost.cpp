class Solution {
public:
    static bool cmp(vector<int> & a, vector<int> &b)
    {
        return a[2]<b[2];
    }

    int findParent(int children, vector<int>&parent)
    {
        if(parent[children] == -1)
            return children;
        
        return parent[children] = findParent(parent[children], parent);
    }

    bool unionFind(int source , int destination, vector<int> &parent, vector<int> &rank)
    {
        int parentA = findParent(source, parent);
        int parentB = findParent(destination, parent);

        if(parentA == parentB)
            return false;

        if(rank[parentA] >= rank[parentB])
        {
            rank[parentA] += rank[parentB];
            parent[parentB] = parentA;
        }
        else
        {
            rank[parentB] += rank[parentA];
            parent[parentA] = parentB;
        }

        return true;
    }

    int minimumCost(int n, vector<vector<int>>& connections) {
        vector<int>parent(n+1, -1);
        vector<int>rank(n+1,1);

        sort(connections.begin(), connections.end() , cmp);

        int cost = 0;
        int total = 0;
        for(int i = 0;i<connections.size();i++)
        {
            bool result = unionFind(connections[i][0], connections[i][1], parent, rank);
            if(!result)
                continue;

            cost += connections[i][2];
            total++;
        }

        if(total == n-1)
            return cost;
        else
            return -1;
    }
};
