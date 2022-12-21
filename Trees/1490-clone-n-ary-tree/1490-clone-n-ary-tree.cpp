/*
// Definition for a Node.
class Node {
public:
    int val;
    vector<Node*> children;

    Node() {}

    Node(int _val) {
        val = _val;
    }

    Node(int _val, vector<Node*> _children) {
        val = _val;
        children = _children;
    }
};
*/

class Solution {
    unordered_map<Node*,Node*> mp;
public:
    Node* dfs(Node* root)
    {
        if(!root)
            return NULL;
        
        Node* curr = new Node(root->val);
        mp[root] = curr;
        for(int i=0;i<root->children.size();i++)
        {
            curr->children.push_back(dfs(root->children[i]));
        }
        return curr;
    }
    
    Node* cloneTree(Node* root) {
        Node* curr = dfs(root);
        return curr;
    }
};
