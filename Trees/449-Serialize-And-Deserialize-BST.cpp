class Codec {
public:

    // Encodes a tree to a single string.
    void serialize(TreeNode* root, string &str)
    {
        if(!root)
        {
            str += '!';
            return;
        }
        str += to_string(root->val) + '&';
        
        serialize(root->left,str);
        serialize(root->right,str);
    }
    string serialize(TreeNode* root) {
        
        string str = "";
        serialize(root,str);
        return str;
    }

    // Decodes your encoded data to tree.
    
    TreeNode* deserialize(string data, int &count)
    {
        if(count>=data.length() or data[count]=='!')
        {
            count ++;
            return NULL;
        }
        int entry = 0;
        while(count<data.length())
        {
            if(data[count]>='0' and data[count]<='9')
            {
                entry = (entry*10) + (data[count]-'0');
                count++;
            }
            else
                break;
        }
        count++;
        TreeNode* root = new TreeNode(entry);
        root->left = deserialize(data,count);
        root->right =deserialize(data,count);
        return root;
    }
    
    TreeNode* deserialize(string data) {
        int count = 0;
        return deserialize(data,count);
    }
};
