class Solution {
public:
    
    void findBottom(TreeNode* root,int length,int &maxLength,int &value)
    {
        if(!root)
            return;
        
        if(length>maxLength)
        {
            maxLength = length;
            value = root->val;
        }
        
        findBottom(root->left,length+1,maxLength,value);
        findBottom(root->right,length+1,maxLength,value);
        
        return;
    }
    
    int findBottomLeftValue(TreeNode* root) {
        
        int maxLength = 1;
        int value = root->val;
        
        findBottom(root,1,maxLength,value);
        
        return value;
        
    }
};
