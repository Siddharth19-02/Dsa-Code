class HitCounter {
    int sum;
    queue< pair<int,int> >q;
public:
    HitCounter() {
        sum = 0;
    }
    
    void hit(int timestamp) {
        sum++;
        if(q.empty() or q.front().first != timestamp)
        {
            q.push({timestamp,1});
        }
        else
        {
            pair<int,int> curr = q.front();
            q.pop();
            q.push({timestamp,curr.second+1});
        }
    }
    
    int getHits(int timestamp) {
        while(!q.empty() and timestamp-q.front().first>=300)
        {
            sum -= q.front().second;
            q.pop();
        }
        
        return sum;
    }
};

/*
m-2 binary search can also be applied on this question as make a vector and find timestamp-300 element
every time so here how in this question binary search can be applied
*/

/**
 * Your HitCounter object will be instantiated and called as such:
 * HitCounter* obj = new HitCounter();
 * obj->hit(timestamp);
 * int param_2 = obj->getHits(timestamp);
 */
