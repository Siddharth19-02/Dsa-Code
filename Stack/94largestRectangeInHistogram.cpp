class Solution {
public:
    int largestRectangleArea(vector<int>& arr) {
        
        int n = arr.size();
        int max_area = 0;
        stack<int>s;
        int i;
        
        for(i=0;i<arr.size();i++)
        {
            while(!s.empty() and arr[s.top()]>arr[i])
            {
                int index = s.top();
                s.pop();
                if(s.empty())
                {
                    max_area = max(max_area,(i)*arr[index]);
                }
                else
                {
                    max_area = max(max_area,(i-s.top()-1)*arr[index]);
                }
            }
            s.push(i);
        }
        
        while(!s.empty() )
        {
            int index = s.top();
            s.pop();
            if(s.empty())
            {
                max_area = max(max_area,(i)*arr[index]);
            }
            else
            {
                max_area = max(max_area,(i-s.top()-1)*arr[index]);
            }
        }
        
        
        return max_area;
        
    }
};
