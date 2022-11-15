class Solution {
public:
    int recursive(TreeNode* root, int lef, int rig) {
        if (!root)
            return 0;
        
        TreeNode *right = root, *left = root;
        
        if (!lef) 
            while ((left = left->left)) 
                lef++;
        
        if (!rig) 
            while ((right = right->right)) 
                rig++;
        
        if (lef == rig) 
            return pow(2, lef + 1) - 1;
        
        return 1 + recursive(root->left, lef - 1, 0) + recursive(root->right, 0, rig - 1);
    }
    int countNodes(TreeNode* root) {
        return recursive(root, 0, 0);
    }
};
