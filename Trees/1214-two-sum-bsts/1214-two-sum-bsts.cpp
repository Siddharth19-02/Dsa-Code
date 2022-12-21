class Solution {
public:
    void findLeft(TreeNode* root,stack<TreeNode*> &s1)
    {
        while(root)
        {
            s1.push(root);
            root = root->left;
        }
    }
    
    void findRight(TreeNode* root,stack<TreeNode*> &s2)
    {
        while(root)
        {
            s2.push(root);
            root = root->right;
        }
    }
    
    bool twoSumBSTs(TreeNode* root1, TreeNode* root2, int target) {
        
        stack<TreeNode*>s1;
        stack<TreeNode*>s2;
        
        findLeft(root1,s1);
        findRight(root2,s2);
        
        while(!s1.empty() and !s2.empty())
        {
            TreeNode* first = s1.top();
            s1.pop();
            
            TreeNode* second = s2.top();
            s2.pop();
            
            long curr = (long)first->val + second->val;
            if(curr == target)
            {
                return true;
            }
            else if(curr > target)
            {
                s1.push(first);
                findRight(second->left,s2);
            }
            else
            {
                s2.push(second);
                findLeft(first->right,s1);
            }
        }
        return false;
    }
};
