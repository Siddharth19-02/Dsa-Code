class Solution {
public:
    int findParent(int child, vector<int> &parent) 
    {
        if (parent[child] == -1)
            return child;
        return parent[child] = findParent(parent[child], parent);
    }

    void findunion(int x, int y, vector<int> &parent, vector<int>& rank) 
    {
        int s1 = findParent(x, parent);
        int s2 = findParent(y, parent);

        if (s1 == s2)
            return;

        if (rank[s1] >= rank[s2]) 
        {
            parent[s2] = s1;
            rank[s1] += rank[s2];
        } 
        else 
        {
            parent[s1] = s2;
            rank[s2] += rank[s1];
        }
    }

    int minimumHammingDistance(vector<int>& source, vector<int>& target, vector<vector<int>>& allowedSwaps) {
        
        int n = source.size();

        vector<int>parent(n, -1);
        vector<int>rank(n,1);

        for (vector<int> &allowedSwap : allowedSwaps) 
        {
            findunion(allowedSwap[0], allowedSwap[1], parent, rank);
        }

        unordered_map<int, unordered_multiset<int> > mp;
        for (int i = 0; i < n; i++) 
        {
            if(source[i] != target[i])
                mp[findParent(i, parent)].insert(source[i]);
        }
        
        int difference = 0;
        for(int i=0;i<n;i++)
        {
            if(source[i] != target[i])
            {
                unordered_multiset<int> &s = mp[findParent(i, parent)];
                auto it = s.find(target[i]);
                if(it != s.end())
                {
                    s.erase(it);
                }
                else
                {
                    difference++;
                }
            }
        }

        return difference;
    }
};
