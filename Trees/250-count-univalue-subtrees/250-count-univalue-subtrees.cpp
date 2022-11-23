class Solution {
public:
    bool univalueTrees(TreeNode* root,int &count)
    {
        if(!root)
            return true;
        
        if(!root->left and !root->right)
        {
            count += 1;
            return true;
        }
        
        bool left  = univalueTrees(root->left,count);
        bool right = univalueTrees(root->right,count);
        
        if(left and right)
        {
            int currCount = 0;
            currCount = (!root->left)?currCount+1:((root->left->val == root->val)?currCount+1:currCount);
            currCount = (!root->right)?currCount+1:((root->right->val == root->val)?currCount+1:currCount);
            if(currCount == 2)
                count +=1;
            return (currCount == 2);
        }
        
        return left && right;
    }
    
    int countUnivalSubtrees(TreeNode* root) {
        int count = 0;
        univalueTrees(root,count);
        return count;
    }
};
