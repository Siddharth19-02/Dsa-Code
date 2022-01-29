class Solution {
public:
    int find(int v,vector<int>&parent)
    {
       
        if(parent[v]==v)
            return v;
        return  parent[v] = find(parent[v],parent);
    }
    
    bool validateBinaryTreeNodes(int n, vector<int>& leftChild, vector<int>& rightChild) {
       
        vector<int>vec(n);
        for(int i=0;i<n;i++)
            vec[i] = i;
        int count = 0;

        for(int i=0;i<n;i++)
        {               
            int curr = i;
            
            if(leftChild[curr]!=-1)
            {
                if(vec[leftChild[curr]]!=leftChild[curr])    // agar phela sa koi parent h toh wapas bhej do false h
                    return false;       // ek node sa ek hih baap bnaga
                
                int a = find(curr,vec);
                int b = find(leftChild[curr],vec);     // agar ek region ka 2 nodes ka beech hoh rha h false krdo
                if(a==b)
                    return false;
                vec[b] = a;
            }
            
            if(rightChild[curr]!=-1)
            {  // pura tree ek hih component hota h ye dekhna ka liya hmm ye check kr rha h 
                if(vec[rightChild[curr]]!=rightChild[curr])
                    return false;
                int a = find(curr,vec);
                int b = find(rightChild[curr],vec);
                
                if(a==b)
                    return false;
                vec[b] = a;
            }
            
        }
        
        for(int i=0;i<n;i++)
            if(vec[i]==i)
                count++;
       
        return (count==1);
    }
};
