class RecentCounter {
    queue<int>q;
public:
    RecentCounter() {
        
    }
    
    int ping(int t) {
        while(!q.empty() and q.front()<t-3000)
            q.pop();
        
        q.push(t);
        
        return q.size();
    }
};
