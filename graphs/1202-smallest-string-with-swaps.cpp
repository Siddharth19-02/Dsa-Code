class Solution {
public:
    vector<int> parent;
    vector<int> rank;

    int findParent(int x) 
    {
        if (parent[x] == -1)
            return x;
        return parent[x] = findParent(parent[x]);
    }

    void findunion(int x, int y) 
    {
        int s1 = findParent(x);
        int s2 = findParent(y);

        if (s1 == s2)
            return;

        if (rank[s1] > rank[s2]) 
        {
            parent[s2] = s1;
            rank[s1] = +rank[s2];
        } 
        else 
        {
            parent[s1] = s2;
            rank[s2] = +rank[s1];
        }
    }

    string smallestStringWithSwaps(string s, vector<vector<int>>& pairs) {

        int n = s.length();
        parent.resize(n, -1);
        rank.resize(n, -1);

        for (auto it : pairs) 
        {
            findunion(it[0], it[1]);
        }

        unordered_map<int, string > mp;
        for (int i = 0; i < n; i++) 
        {
            mp[findParent(i)].push_back(s[i]);
        }

        for (auto it : mp) 
        {
            string vec = it.second;
            sort(vec.begin(),vec.end(),greater<int>());
            mp[it.first] = vec;
        }

        string ans = "";
        for (int i = 0; i < n; i++) 
        {
            int parent = findParent(i);
            ans +=  mp[parent][mp[parent].size()-1];
            mp[parent].pop_back();
        }

        return ans;
    }
};
