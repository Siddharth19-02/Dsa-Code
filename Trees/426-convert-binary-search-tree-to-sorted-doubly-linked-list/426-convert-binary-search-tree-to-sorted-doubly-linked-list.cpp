class Solution {
public:
    void convertor(Node* root,Node* &back,Node* &front)
    {
        if(!root)
            return;
        
        convertor(root->right,back,front);
        
        if(back)
        {
            root->right = back;
            back->left = root;
        }
        else
        {
            front = root;
        }
        
        back = root;
        
        convertor(root->left,back,front);
    }
    
    Node* treeToDoublyList(Node* root) {
        if(!root)
            return root;
        
        Node* back = NULL ;
        Node* front=NULL;
        
        convertor(root,back,front);
        back->left = front;
        front->right = back;
        return back;
    }
};
