class Solution {
public:
    bool validateStackSequences(vector<int>& push, vector<int>& pop) {
        int i = 0,j = 0;
        int n = push.size();
        int temp = 0;
        for(int x : push){
            push[i] = x;
            i = i + 1;
            while(i > 0 && push[i-1] == pop[j]){
                i--;
                j++;
            }
        }
        return i == 0;
    }
};


// class Solution {
// public:
//     bool validateStackSequences(vector<int>& pushed, vector<int>& popped) {
     
//         stack<int>s;
        
//         int i=0 , j=0;
//         int n = pushed.size();
//         int m = popped.size();
        
//         while(i<n or j<m)
//         {
//             while(!s.empty() and s.top()==popped[j])
//             {
//                 s.pop();
//                 j++;
//             }
            
//             if(i<n)
//             {
//                 s.push(pushed[i]);
//                 i++;
//             }
            
//             if(i>=n and !s.empty() and s.top()!=popped[j])
//                 return false;
            
//         }
//         return true;
//     }
// };
