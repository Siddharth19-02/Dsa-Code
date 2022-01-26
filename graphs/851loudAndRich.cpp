class Solution {
    unordered_map<int, vector<int>> mp;
    vector<int> res;
    public:
    
    int dfs(int i, vector<int>& quiet) {
        if (res[i] >= 0) return res[i];
        res[i] = i;
        for (int j : mp[i]) if (quiet[res[i]] > quiet[dfs(j, quiet)]) res[i] = res[j];
        return res[i];
    }
    
    vector<int> loudAndRich(vector<vector<int>>& richer, vector<int>& quiet) {
        for (auto v : richer) mp[v[1]].push_back(v[0]);
        res = vector<int> (quiet.size(), -1);
        for (int i = 0; i < quiet.size(); i++) dfs(i, quiet);
        return res;
    }
};

