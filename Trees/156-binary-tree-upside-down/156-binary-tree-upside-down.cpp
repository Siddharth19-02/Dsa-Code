class Solution {
public:
    TreeNode* upsideDownBinaryTree(TreeNode* root) {
        
        if(!root)
            return NULL;
        
        if(!root->left and !root->right)
            return root;
        
        TreeNode* currBoss = upsideDownBinaryTree(root->left);
        
        TreeNode* currRoot = root->left;
        currRoot->left = root->right;
        currRoot->right = root;
        
        root->left = root->right = NULL;
        
        return currBoss;
    }
};
