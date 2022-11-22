class Solution {
public:
    
    TreeNode* createTree(string s,int &i)
    {
        if(i>=s.length())
            return NULL;
        
        string curr = "";
        
        if(s[i] == '-')
        {
            curr += '-';
            i++;
        }
       
        while(s[i]>='0' and s[i]<='9')
        {
            curr += s[i];
            i++;
        }
        
        TreeNode* root = new TreeNode(stoi(curr));
        
        if(s[i] == '(')
        {
            i++;
            root->left = createTree(s,i);
            i++;
        }
        
        if(s[i] == '(')
        {
            i++;
            root->right = createTree(s,i);
            i++;
        }
        
        return root;
    }
    
    TreeNode* str2tree(string s) {
        
        if(s.size() == 0)
            return NULL;
        
        int i = 0;
        
        return createTree(s,i);
        
    }
};
