class Solution {
public:
    int minCamera(TreeNode* root,int &sum)
    {
        if(!root)
            return 0;
        
        if(!root->left and !root->right)
            return 1;
        
        int x = minCamera(root->left,sum);
        int y = minCamera(root->right,sum);
        
        if(x==1 or y==1)
        {
            sum += 1;
            return 2;
        }
        else if(x==2 or y==2)
        {
            return 0;
        }
        else
            return 1;
        
    }
    
    int minCameraCover(TreeNode* root) {
        
        int sum = 0;
        
        if(minCamera(root,sum)==1)
            sum += 1;
        
        return sum;
    }
};
