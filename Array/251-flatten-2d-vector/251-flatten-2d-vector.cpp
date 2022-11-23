class Vector2D
{
    vector<int> res;
    int x;
public:
    Vector2D(vector<vector<int>>& vec) {
        for(int i=0;i<vec.size();i++)
            for(int j=0;j<vec[i].size();j++)
                res.push_back(vec[i][j]);
        x=0;
    }
    
    int next() {
        return res[x++];
    }
    
    bool hasNext() {
        return x<res.size();
    }
};

/**
 * Your Vector2D object will be instantiated and called as such:
 * Vector2D* obj = new Vector2D(vec);
 * int param_1 = obj->next();
 * bool param_2 = obj->hasNext();
 */
