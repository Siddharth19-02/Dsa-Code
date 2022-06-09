class Solution {
public:
    
    void allNumbers(int num,int n,vector<int> &vec)
    {
        if(num>n)
            return;
        
        for(int i=0;i<=9;i++)
        {
            num += i;
            if(num<=n and num!=0)
            {
                vec.push_back(num);
                allNumbers(num*10,n,vec);
            }
            else if(num>n)
                return;
            num -= i;
        }
    }
    
    vector<int> lexicalOrder(int n) {
        
        vector<int>vec;
        
        int num = 0;
        
        allNumbers(num,n,vec);
        
        return vec;
    }
};
