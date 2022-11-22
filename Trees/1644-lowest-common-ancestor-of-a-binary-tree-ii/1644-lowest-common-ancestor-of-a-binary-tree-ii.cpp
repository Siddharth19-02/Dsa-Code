/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
class Solution {
public:
    TreeNode* lca(TreeNode* root, TreeNode* p, TreeNode* q,int &count)
    {
        if(!root)
            return NULL;
        
        TreeNode* left = lca(root->left,p,q,count);
        TreeNode* right= lca(root->right,p,q,count);
        
        if(root == p)
        {
            count++;
            return root;
        }
        
        if(root == q)
        {
            count++;
            return root;
        }
        
        if(left and right)
            return root;
        
        return (left)?left:right;
    }
    
    TreeNode* lowestCommonAncestor(TreeNode* root, TreeNode* p, TreeNode* q) {
        
        int count = 0;
        TreeNode* curr = lca(root,p,q,count);
        if(count == 2)
            return curr;
        else
            return NULL;
    }
};
