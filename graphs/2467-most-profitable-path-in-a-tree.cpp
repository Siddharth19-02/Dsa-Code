class Solution {
    private:
    vector<vector<int>> tree;
    int n;
public:
    int mostProfitablePath(int source, int parent, int time, int bob, vector<int>& amount, vector<int> &distanceFromBob)
    {
        int maxIncome = 0;
        int maxIncomeFromChild = INT_MIN;

        if(source == bob)
            distanceFromBob[source] = 0;

        for(int child : tree[source])
        {
            if (child != parent)
            {
                maxIncomeFromChild = max(maxIncomeFromChild, mostProfitablePath(child, source,time+1, bob, amount, distanceFromBob) );
            distanceFromBob[source] =min(distanceFromBob[source],distanceFromBob[child] + 1);
            }
        }

        if (distanceFromBob[source] > time) 
            maxIncome += amount[source];
        else if(distanceFromBob[source] == time)
            maxIncome += amount[source] / 2;

        return (maxIncomeFromChild == INT_MIN)?maxIncome:maxIncome+maxIncomeFromChild;
    }

    int mostProfitablePath(vector<vector<int>>& edges, int bob,vector<int>& amount) {
        n = amount.size();
        tree.resize(n, vector<int>());

        for (vector<int> edge : edges) 
        {
            tree[edge[0]].push_back(edge[1]);
            tree[edge[1]].push_back(edge[0]);
        }

        vector<int> distanceFromBob(n,n);

        return mostProfitablePath(0, 0, 0,bob, amount, distanceFromBob);
        
    }
};
