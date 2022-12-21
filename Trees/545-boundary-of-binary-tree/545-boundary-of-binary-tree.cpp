class Solution {
public:
    void boundaryLeft(TreeNode* root,vector<int> &res)
    {
        if(!root)
            return;
        
        if(root->left)
        {
            res.push_back(root->val);
            boundaryLeft(root->left,res);
        }
        else if(root->right)
        {
            res.push_back(root->val);
            boundaryLeft(root->right,res);
        }
    }
    
    void boundaryRight(TreeNode* root,vector<int> &res)
    {
        if(!root)
            return;
        
        if(root->right)
        {
            boundaryRight(root->right,res);
            res.push_back(root->val);
        }
        else if(root->left)
        {
            boundaryRight(root->left,res);
            res.push_back(root->val);
        }
    }
    
    void leaves(TreeNode* root,vector<int> &res)
    {
        if(!root)
            return;
        
        if(!root->left and !root->right)
        {
            res.push_back(root->val);
            return;
        }
        
       leaves(root->left,res);
       leaves(root->right,res);
    }
    
    
    vector<int> boundaryOfBinaryTree(TreeNode* root) {
        vector<int> res;
        if(!root)
            return res;
        
        res.push_back(root->val);
        
        boundaryLeft(root->left,res);
        leaves(root->left,res);
        leaves(root->right,res);
        boundaryRight(root->right,res);
        
        return res;
    }
};
