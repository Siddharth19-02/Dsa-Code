// Definition for a Node.
class Node {
public:
    int val;
    Node* left;
    Node* right;
    Node* parent;
};
*/
## m-1
class Solution {
public:
    Node* lowestCommonAncestor(Node* p, Node * q) {
        unordered_set<Node*> s;

        while (p != NULL) 
        {
            s.insert(p);
            p = p->parent;
        }

        while (q != NULL) {
            if (s.find(q) != s.end())
                return q;
            q = q->parent;
        }

        return NULL;


    }
};

##m-2
// find the root and then do normally we find LCA

##m-3
Node* lowestCommonAncestor(Node* p, Node * q) {
    Node *pNode = p;
    int pNode_count = 0;
    Node *qNode = q;
    int qNode_count = 0;

    while(pNode != NULL) {
        pNode = pNode->parent;
        pNode_count++;
    }
    while(qNode != NULL) {
        qNode = qNode->parent;
        qNode_count++;
    }

    while(qNode_count != pNode_count) {
        if (pNode_count > qNode_count) {
            pNode_count--;
            p = p->parent;
        }else {
            qNode_count--;
            q = q->parent;
        }
    }

    while(p != q) {
        p = p->parent;
        q = q->parent;
    }
    return p;
}

##m-4
Node* lowestCommonAncestor(Node* p, Node * q) {
    Node* nxt;
    while (p) {
        nxt = p->parent;
        p->parent = nullptr;
        p = nxt;
    }
    while (q->parent) {
        q = q->parent;
    }
    return q;
}
