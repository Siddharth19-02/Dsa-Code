class Solution {
    set<int>s;
    vector<TreeNode*>res;
public:
    TreeNode* delNodesHelper(TreeNode* root)
    {
        if(!root)
            return NULL;
        
        root->left = delNodesHelper(root->left);
        root->right = delNodesHelper(root->right);
        
        if(s.find(root->val)!=s.end())
        {
            if(root->left)
                res.push_back(root->left);
            if(root->right)
                res.push_back(root->right);
            
            root=NULL;
        }
        return root;
    }
    vector<TreeNode*> delNodes(TreeNode* root, vector<int>& to_delete) {
        
        for(int i=0;i<to_delete.size();i++)
            s.insert(to_delete[i]);
        
        if(delNodesHelper(root))
            res.push_back(root);
        return res;
    }
};
