class Solution {
public:
    void verifyOrder(vector<int> &preorder,int mini,int maxi,int &index)
    {
        if(index == preorder.size())
            return;
        
        if(preorder[index]>=mini and preorder[index]<=maxi)
        {
            int rank = index;
            index++;
            verifyOrder(preorder,mini,preorder[rank]-1,index);
            verifyOrder(preorder,preorder[rank]+1,maxi,index);
        }
        return ;
    }
    
    bool verifyPreorder(vector<int>& preorder) {
        
        int index = 0;
        int mini = INT_MIN;
        int maxi = INT_MAX;
        
        verifyOrder(preorder,mini,maxi,index);
        
        return (index == preorder.size());
    }
};
