/**
 * Definition for a Node.
 * struct Node {
 *     int val;
 *     Node *left;
 *     Node *right;
 *     Node *random;
 *     Node() : val(0), left(nullptr), right(nullptr), random(nullptr) {}
 *     Node(int x) : val(x), left(nullptr), right(nullptr), random(nullptr) {}
 *     Node(int x, Node *left, Node *right, Node *random) : val(x), left(left), right(right), random(random) {}
 * };
 */

class Solution {
    unordered_map<Node*,NodeCopy*> mp;
public:
    NodeCopy* dfs(Node* root)
    {
        if(!root)
            return NULL;
        
        NodeCopy* curr = new NodeCopy(root->val);
        mp[root] = curr;
        curr->left = dfs(root->left);
        curr->right= dfs(root->right);
        return curr;
    }
    void cloneOne(Node* root,NodeCopy* curr)
    {
        if(!root)
            return;
        
        curr->random = mp[root->random];
        cloneOne(root->left,curr->left);
        cloneOne(root->right,curr->right);
    }
    
    NodeCopy* copyRandomBinaryTree(Node* root) {
        
        NodeCopy* curr = dfs(root);
        cloneOne(root,curr);
        return curr;
    }
};
