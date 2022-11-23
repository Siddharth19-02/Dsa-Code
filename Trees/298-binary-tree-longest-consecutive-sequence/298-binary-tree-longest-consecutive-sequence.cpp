class Solution {
public:
    int longestPath(TreeNode* root,int &maxLength)
    {
        if(!root)
            return 0;
        
        if(!root->left and !root->right)
            return 1;
        
        int left = longestPath(root->left,maxLength);
        int right= longestPath(root->right,maxLength);
        
        int currentLength = 0;
        if(left)
        {
            if(root->val+1 == root->left->val)
            {
                maxLength = max(maxLength,left+1);
                currentLength = left;
            }
        }
        
        if(right)
        {
            if(root->val+1 == root->right->val)
            {
                maxLength = max(maxLength,right+1);
                currentLength = max(currentLength,right);
            }
        }
        return currentLength+1;
    }
    
    int longestConsecutive(TreeNode* root) {
        int maxLength = 1;
        longestPath(root,maxLength);
        return maxLength;
    }
};
