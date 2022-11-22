class Solution {
public:
    TreeNode* lca(TreeNode* root,unordered_set<int> &s)
    {
        if(!root)
            return NULL;
        
        if(s.find(root->val)!=s.end())
            return root;
        
        TreeNode* left = lca(root->left,s);
        TreeNode* right= lca(root->right,s);
        
        if(left and right)
            return root;
        else if(left)
            return left;
        else
            return right;
    }
    
    TreeNode* lowestCommonAncestor(TreeNode* root, vector<TreeNode*> &nodes) {
        unordered_set<int>s;
        for(auto x : nodes)
            s.insert(x->val);
        
        return lca(root,s);
    }
};
