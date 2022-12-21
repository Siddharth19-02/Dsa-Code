//m-1
// tried solving it through maximum produt of splitted tree but this one can be done through 
// m-2 also ... 

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
    
    int equalSumTree(TreeNode* root,int &sum,bool &ans)
    {
        if(!root)
            return 0;
        
        if(!root->left and !root->right)
            return root->val;
        
        int left = equalSumTree(root->left,sum,ans);
        if(ans)
            return -1;
        int right = equalSumTree(root->right,sum,ans);
        if(ans)
            return -1;
        
        if(root->left)
        {
            int currAns = (sum-left);
            if(left == currAns)
            {
                ans = true;
                return -1;
            }
        }
        
        if(root->right)
        {
            int currAns = (sum-right);
            if(right == currAns)
            {
                ans = true;
                return -1;
            }
        }
        
        
        return (root->val + left + right);
    }
    
    bool checkEqualTree(TreeNode* root) {
        int sum = sumOfTree(root);
        bool ans = false;
        equalSumTree(root,sum,ans);
        return ans;
    }
};

/*
m-2
class Solution {
    Stack<Integer> seen;
    public boolean checkEqualTree(TreeNode root) {
        seen = new Stack();
        int total = sum(root);
        seen.pop();
        if (total % 2 == 0)
            for (int s: seen)
                if (s == total / 2)
                    return true;
        return false;
    }

    public int sum(TreeNode node) {
        if (node == null) return 0;
        seen.push(sum(node.left) + sum(node.right) + node.val);
        return seen.peek();
    }
}
*/
