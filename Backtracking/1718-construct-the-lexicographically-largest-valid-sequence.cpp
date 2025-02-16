class Solution {
public:
    bool constructVector(vector<int> &res, vector<bool>&numberUsed, int index) 
    {

        if(index == res.size())
        {
            return true;
        }

        if(res[index] != 0)
            return constructVector(res, numberUsed, index+1);


        for(int i = numberUsed.size() - 1;i>=0;i--)
        {
            if(numberUsed[i])
                continue;

            if(i+1 != 1)
            {
                if(i+index+1 >= res.size() || res[i+index+1] != 0)
                {
                    continue;
                }
                res[index] = i+1;
                res[i + index + 1] = i+1;
            }
            else
            {
                res[index] = i+1;
            }

            numberUsed[i] = true;

            if(constructVector(res,numberUsed,index+1))
                return true;

            numberUsed[i] = false;

            if(i+1 != 1)
                res[i + index + 1] = 0;

            res[index] = 0;

        }

        return false;
    }

    vector<int> constructDistancedSequence(int n) {
        
        vector<int>res(2*n-1,0);
        vector<bool>numberUsed(n,false);

        constructVector(res, numberUsed, 0);

        return res;
    }
};
