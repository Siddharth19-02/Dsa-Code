class Solution {
public:
    void rightSide(TreeNode* root,unordered_map<int,int> &mp,vector<int> &result,int dir)
    {
        if(!root)
            return;
        
        if(mp.find(dir)==mp.end())
        {
            result.push_back(root->val);
            mp[dir]++;
        }
        rightSide(root->right,mp,result,dir+1);
        rightSide(root->left,mp,result,dir+1);
    }
    
    vector<int> rightSideView(TreeNode* root) {
        unordered_map<int,int>mp;
        vector<int>result;
        
        int dir = 0;
        
        rightSide(root,mp,result,dir);
        
        
        return result;
    }
};
