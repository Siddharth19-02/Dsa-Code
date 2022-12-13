class Solution {
public:
    int sumOfTree(TreeNode* root)
    {
        if(!root)
            return 0;
        
        if(!root->left and !root->right)
            return root->val;
        
        return (root->val + sumOfTree(root->left) + sumOfTree(root->right));
    }
    
    int maxProductTree(TreeNode* root,int sum,long long int &product)
    {
        if(!root)
            return 0;
        
        if(!root->left and !root->right)
            return root->val;
        
        long long int left = maxProductTree(root->left,sum,product);
        long long int right = maxProductTree(root->right,sum,product);
        
        if(left)
        {
            long long int currAns = (left * (sum-left));
            product = max(product,currAns);
        }
        
        if(right)
        {
            long long int currAns = (right * (sum-right));
            product = max(product,currAns);
        }
        
        
        return (root->val + left + right);
    }
    
    int maxProduct(TreeNode* root) {
        int sum = sumOfTree(root);
        long long product = 0;
        
        maxProductTree(root,sum,product);
        
        return (product%1000000007);
    }
};
