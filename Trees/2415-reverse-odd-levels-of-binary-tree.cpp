class Solution {
public:
    void reverseLevel(TreeNode* lef,TreeNode* rig,int level)
    {
        if(!lef)
            return;
        
        reverseLevel(lef->left,rig->right,level+1);
        reverseLevel(lef->right,rig->left,level+1);
        
        if(level%2)
        {
            int val = lef->val;
            lef->val = rig->val;
            rig->val = val;
        }
    }
    
    TreeNode* reverseOddLevels(TreeNode* root) {
        
        if(!root or (!root->left and !root->right))
            return root;
        
        int level = 1;
        reverseLevel(root->left,root->right,level);
        return root;
    }
};
