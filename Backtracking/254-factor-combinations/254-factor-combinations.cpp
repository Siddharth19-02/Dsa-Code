class Solution {
public:
    void getResult(vector<vector<int>>&res,vector<int>&factors,int n,int start)
    {
        for(int i=start;i<=n/i;i++)
        {
            if(n%i==0)
            {
                factors.push_back(i);
                factors.push_back(n/i);
                res.push_back(factors);
                factors.pop_back();
                getResult(res,factors,n/i,i);
                factors.pop_back();
            }
        } 
    }
    vector<vector<int>> getFactors(int n)
    {
        vector<vector<int>> res;
        vector<int>factors;
        getResult(res,factors,n,2);
        return res;
    }
};
