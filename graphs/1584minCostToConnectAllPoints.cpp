class point{
    public:
    int x;
    int y;
    int distance;
    point()
    {
        
    }
    point(int x,int y,int distance)
    {
        this->x = x;
        this->y = y;
        this->distance =distance;
    }
};

bool mycmp(point &a,point &b)
{
    return a.distance < b.distance;
}

class Solution {
public:
    
    int finder(int x,vector<int>&parent)
    {
        if(x==parent[x])
            return x;
        return parent[x] = finder(parent[x],parent);
    }
    
    bool path_compression(int first,int second,vector<int>&parent,vector<int>&rank)
    {
        int parentx = finder(first,parent);
        int parenty = finder(second,parent);
        
        if(parentx==parenty)
            return false;
        
        if(rank[parentx]>=rank[parenty])
        {
            rank[parentx] += rank[parenty];
            parent[parenty] = parentx;
        }
        else
        {
            rank[parenty] += rank[parentx];
            parent[parentx] = parenty;
        }
        
        return true;
    }
    
    int minCostConnectPoints(vector<vector<int>>& points) {
        
        int n = points.size();
        vector<point>vec;
        for(int i=0;i<n;i++)
        {
            for(int j=i+1;j<n;j++)
            {
                point p;
                p.x = i;
                p.y = j;
                p.distance = abs(points[i][0]-points[j][0]) + abs(points[i][1] - points[j][1]);
                vec.push_back(p);
            }
        }
        
        sort(vec.begin(),vec.end(),mycmp);
        
        vector<int>parent(n);
        vector<int>rank(n);
        for(int i=0;i<n;i++)
        {
            parent[i] = i;
            rank[i] = 1;
        }
        
        int i = 0;
        int j = 0;
        int cost = 0;
        while(i<n-1)
        {
            point a = vec[j];
            
           if(path_compression(a.x,a.y,parent,rank))
           {
               cost += a.distance;
                i++;
           }
            j++;
        }
        return cost;
    }
};
