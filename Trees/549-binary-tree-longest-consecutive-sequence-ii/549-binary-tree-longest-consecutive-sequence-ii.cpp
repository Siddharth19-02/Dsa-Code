class Solution {
public:
    pair<int,int> longestPath(TreeNode* root,int &maxLength)
    {
        if(!root)
            return {0,0};
        
        if(!root->left and !root->right)
            return {1,1};
        
        pair<int,int> left = longestPath(root->left,maxLength);
        pair<int,int> right= longestPath(root->right,maxLength);
        
        int currentLengthIncr = 0;
        int currentLengthDecr = 0;
        if(root->left)
        {
            if(root->val+1 == root->left->val)
            {
                currentLengthIncr = left.first;
            }
            if(root->val-1 == root->left->val)
            {
                currentLengthDecr = left.second;
            }
        }
        
        if(root->right)
        {
            if(root->val+1 == root->right->val)
            {
                currentLengthIncr = max(currentLengthIncr,right.first);
            }
            if(root->val-1 == root->right->val)
            {
                currentLengthDecr = max(currentLengthDecr,right.second);
            }
        }
        maxLength = max(maxLength,currentLengthIncr+currentLengthDecr+1);
        return {currentLengthIncr+1,currentLengthDecr+1};
    }
    
    int longestConsecutive(TreeNode* root) {
        int maxLength = 1;
        longestPath(root,maxLength);
        return maxLength;
    }
};
    
