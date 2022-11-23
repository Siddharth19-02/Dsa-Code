class Solution {
public:
    int removeLeaves(TreeNode* root,map<int,vector<int> >&mp)
    {
        if(!root)
            return 0;
        
        if(!root->left and !root->right)
        {
            mp[0].push_back(root->val);
            return 1;
        }
        
        int left = removeLeaves(root->left,mp);
        int right = removeLeaves(root->right,mp);
        
        int maxi = max(left,right);
        
        mp[maxi].push_back(root->val);
        return maxi+1;
    }
    
    vector<vector<int>> findLeaves(TreeNode* root) {
        int level = 0;
        vector<vector<int>> res;
        map<int,vector<int> >mp;
        removeLeaves(root,mp);
        for(auto x : mp)
            res.push_back(x.second);
        return res;
    }
};
