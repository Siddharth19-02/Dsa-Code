class Solution {
public:
    vector<vector<int>> verticalOrder(TreeNode* root) {

        if(!root)
            return {};
            
        queue< pair<TreeNode*,int> >q;
        map<int,vector<int> >mp;
        vector<vector<int>> res;
        q.push({root,0});

        while(!q.empty())
        {
            int size = q.size();
            for(int i=0;i<size;i++)
            {
                pair<TreeNode*,int> curr = q.front();
                q.pop();
                mp[curr.second].push_back(curr.first->val);

                TreeNode* now = curr.first;
                if(now->left)
                {
                    q.push({now->left,curr.second-1});
                }

                if(now->right)
                {
                    q.push({now->right,curr.second+1});
                }
            }
        }

        for(auto x : mp)
            res.push_back(x.second);
        
        return res;

    }
};
