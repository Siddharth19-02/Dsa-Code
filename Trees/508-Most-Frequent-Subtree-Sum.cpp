class Solution {
    unordered_map<int,int>mp;
    vector<int>res;
public:
    int findFrequent(TreeNode* root,int &maxOccurence)
    {
        if(!root)
            return 0;
        
        if(!root->left and !root->right)
        {
            mp[root->val]++;
            if(mp[root->val]>maxOccurence)
            {
                maxOccurence = mp[root->val];
                res.clear();
                res.push_back(root->val);
            }
            else if(mp[root->val]==maxOccurence)
            {
                res.push_back(root->val);
            }
            return root->val;
        }
        
        int left = findFrequent(root->left,maxOccurence);
        int right=findFrequent(root->right,maxOccurence);
        
        int sum = 0;
        sum += root->val + left + right;
        mp[sum]++;
        if(mp[sum]>maxOccurence)
        {
            maxOccurence = mp[sum];
            res.clear();
            res.push_back(sum);
        }
        else if(mp[sum]==maxOccurence)
        {
            res.push_back(sum);
        }
        return sum;
        
        
    }
    vector<int> findFrequentTreeSum(TreeNode* root) {
        int maxOccurence = 0;
        findFrequent(root,maxOccurence);
        return res;
        
    }
};
