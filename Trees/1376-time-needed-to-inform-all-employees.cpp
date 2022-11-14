class treeNode
{
    public:
    int time;
    vector<treeNode*> children;
    
    treeNode(int time)
    {
        this->time = time;
        children.clear();
    }
};

class Solution {
public:
    void createTree(int node,vector<treeNode*> &nodes,vector<int> &manager,vector<int> &informTime)
    {
        if(nodes[node] != NULL)
            return;
        
        nodes[node] = new treeNode(informTime[node]);
        
        if(manager[node] == -1)
            return;
        
        if(nodes[manager[node]] == NULL)
        {
            createTree(manager[node],nodes,manager,informTime);
        }
        
        nodes[manager[node]]->children.push_back(nodes[node]);
    }
    
    int dfs(treeNode* node)
    {
        if(node->children.size()==0)
            return node->time;
        
        int totalTime = 0;
        for(int i=0;i<node->children.size();i++)
        {
            int currTime =dfs(node->children[i]);
            totalTime = max(totalTime,currTime);
        }
        return totalTime + node->time;
    }
    
    int numOfMinutes(int n, int headID, vector<int>& manager, vector<int>& informTime) {
        
        vector<treeNode*> nodes(n,NULL);
        
        for(int i=0;i<n;i++)
        {
            createTree(i,nodes,manager,informTime);
        }
        
        return dfs(nodes[headID]);
    }
};
