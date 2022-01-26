class Solution {
public:
    
    int longestpath(TreeNode* root,int& max_edges)
    {
        if(!root)
            return -1;
        
        if(!root->left and !root->right)
            return 0;
        
        int curr_left = longestpath(root->left,max_edges);
        int curr_right=longestpath(root->right,max_edges);
        
        if(curr_left!=-1 and root->val==root->left->val and curr_right!=-1 and root->val==root->right->val)
        {
            max_edges = max(max_edges,curr_left+curr_right+2);
            return max(curr_left,curr_right)+1;
        }
        else if(curr_left!=-1 and root->val==root->left->val)
        {
            max_edges = max(max_edges,curr_left+1);
            return curr_left+1;
        }
        else if(curr_right!=-1 and root->val==root->right->val)
        {
            max_edges = max(max_edges,curr_right+1);
            return curr_right+1;
        }
        else
            return 0;
        
    }
    
    int longestUnivaluePath(TreeNode* root) {
        int max_edges = 0;
        longestpath(root,max_edges);
        return max_edges;
    }
};
