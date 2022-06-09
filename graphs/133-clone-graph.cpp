/*
// Definition for a Node.
class Node {
public:
    int val;
    vector<Node*> neighbors;
    Node() {
        val = 0;
        neighbors = vector<Node*>();
    }
    Node(int _val) {
        val = _val;
        neighbors = vector<Node*>();
    }
    Node(int _val, vector<Node*> _neighbors) {
        val = _val;
        neighbors = _neighbors;
    }
};
*/

class Solution {
public:
    
    Node* clone(Node* node,int data,vector<Node *> &visited)
    {
        if(node==NULL)
            return NULL;
        Node *root = new Node(data);
        cout<<&root<<" "<<root<<" "<<*(&root)<<endl;
        visited[root->val] = root;
        
        for(Node* children : node->neighbors)
        {
            if(visited[children->val]==NULL)
            {
                clone(children,children->val,visited);
            }
            root->neighbors.push_back(visited[children->val]);
        }
        return root;
    }
    
    Node* cloneGraph(Node* node) {
        vector<Node *>visited(1000,NULL);
        Node* root =  clone(node,1,visited);
        for(int i=1;i<5;i++)
            cout<<visited[i]<<" ";
        return root;
        
    }
};
