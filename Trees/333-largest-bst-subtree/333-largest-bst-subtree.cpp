class Curr
{
    public:
    bool isBst;
    int mini;
    int maxi;
    int nodes;

    Curr(int one,int two,int three,bool ans)
    {
        isBst = ans;
        mini = one;
        maxi = two;
        nodes = three;
    }
    
    
};
class Solution {
public:
    Curr largestTree(TreeNode* root,int &maxNodes)
    {
        if(!root)
        {
            return Curr(INT_MAX,INT_MIN,0,true);
        }
        
        if(!root->left and !root->right)
        {
            Curr curr(root->val,root->val,1,true);
            maxNodes = max(maxNodes,1);
            return curr;
        }
        
        Curr left = largestTree(root->left,maxNodes);
        Curr right= largestTree(root->right,maxNodes);
        
        if(left.isBst and right.isBst)
        {
                if(root->val>left.maxi and root->val<right.mini)
                {
                    Curr curr(min(left.mini,root->val),max(right.maxi,root->val),1+left.nodes+right.nodes,true);
                    maxNodes = max(maxNodes,curr.nodes);
                    return curr;
                }
        }
        return Curr(INT_MIN,INT_MAX,0,false);

        
    }
    int largestBSTSubtree(TreeNode* root) {
        int maxNodes = 0;
        largestTree(root,maxNodes);
        return maxNodes;
    }
};

/*
m-2 i first wrote this its messy above one is clean good code see the difference how smartly when root is null
its tackling it and when bst is not how its tackling it
class Curr
{
    public:
    bool isBst;
    int mini;
    int maxi;
    int nodes;
    Curr()
    {
        isBst = false;
        mini = -1;
        maxi = -1;
        nodes = 0;
    }
    Curr(int one)
    {
        isBst = true;
        mini = one;
        maxi = one;
        nodes = 0;
    }
    
    
};
class Solution {
public:
    Curr largestTree(TreeNode* root,int &maxNodes)
    {
        if(!root)
        {
            Curr curr(0);
            return curr;
        }
        
        if(!root->left and !root->right)
        {
            Curr curr(root->val);
            curr.nodes = 1;
            maxNodes = max(maxNodes,1);
            return curr;
        }
        
        Curr left = largestTree(root->left,maxNodes);
        Curr right= largestTree(root->right,maxNodes);
        
        Curr curr;
        if(left.isBst and right.isBst)
        {
            if(root->left and root->right)
            {
                if(root->val>left.maxi and root->val<right.mini)
                {
                    curr.isBst = true;
                    curr.maxi = right.maxi;
                    curr.mini = left.mini;
                    curr.nodes = 1+left.nodes+right.nodes;
                    maxNodes = max(maxNodes,curr.nodes);
                    return curr;
                }
            }
            else if(root->left)
            {
                if(root->val>left.maxi)
                {
                    curr.isBst = true;
                    curr.maxi = root->val;
                    curr.mini = left.mini;
                    curr.nodes = 1+left.nodes;
                    maxNodes = max(maxNodes,curr.nodes);
                    return curr;
                }
            }
            else 
            {
                if(root->val<right.mini)
                {
                    curr.isBst = true;
                    curr.maxi = right.maxi;
                    curr.mini = root->val;
                    curr.nodes = 1+right.nodes;
                    maxNodes = max(maxNodes,curr.nodes);
                    return curr;
                }
            }
        }
        
        return curr;
        
    }
    int largestBSTSubtree(TreeNode* root) {
        int maxNodes = 0;
        largestTree(root,maxNodes);
        return maxNodes;
    }
};
*/
