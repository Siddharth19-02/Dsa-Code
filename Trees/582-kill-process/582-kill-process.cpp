
## m-1 i created tree which was not required 
class treeNode
{
    public:
    int value;
    vector<treeNode*> children;

    treeNode(int value)
    {
        this->value = value;
        children.clear();
    }
};

class Solution {
    unordered_map<int,int>mp;
    unordered_map<int,treeNode*>finder;
public:
    void totalNodes(treeNode* root,vector<int> &result)
    {
        if(!root)
            return ;
        
        result.push_back(root->value);
        
        for(int i =0;i<root->children.size();i++)
        {
            totalNodes(root->children[i],result);
        }
    }
    
    void createTree(int node)
    {
        if(finder.find(node) != finder.end() )
            return;

        finder[node] = new treeNode(node);

        if(mp[node] == 0)
            return;

        if(finder.find( mp[node] ) == finder.end() ) 
        {
            createTree(mp[node]);
        }

        finder[mp[node]]->children.push_back(finder[node]);
    }
    
    vector<int> killProcess(vector<int>& pid, vector<int>& ppid, int kill) {
        
        for(int i = 0;i<pid.size();i++)
            mp[pid[i]] = ppid[i];
        
        for(int i=0;i<pid.size();i++)
        {
            createTree(pid[i]);
        }
        
        treeNode* root = finder[kill];
        
        vector<int>result;
         totalNodes(root,result);
        return result;
    }
};

## without tree

class Solution {
    unordered_map<int, vector<int>> m;
    vector<int> res;
public:
    vector<int> killProcess(vector<int>& pid, vector<int>& ppid, int kill) {
        for(int i=0; i<pid.size(); i++){
            if(ppid[i]!=0) m[ppid[i]].push_back(pid[i]);
        }
        res.push_back(kill);
        dfs(kill);
        return res;
    }
    
    void dfs(int k){
        for(auto i : m[k]){
            res.push_back(i);
            if(m.find(i)!=m.end()) dfs(i);
        }
    }
};
