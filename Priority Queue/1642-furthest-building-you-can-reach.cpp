class Solution {
public:
    int furthestBuilding(vector<int>& heights, int bricks, int ladders) {
        
        priority_queue<int,vector<int>,greater<int>>pq;
        int i = 1;
        for(i=1;i<heights.size();i++)
        {
            int curr = heights[i] - heights[i-1];
            if(curr<=0)
                continue;
            pq.push(curr);
            if(pq.size()<=ladders)
            {
                 continue;
            }
            else 
            {
                int x = pq.top();
                pq.pop();
                if(x<=bricks)
                    bricks -= x;
                else
                    break;
                
            }
            
        }
        return i-1;
    }
};
