class FirstUnique {
    queue<int>q;
    unordered_map<int,int>mp;
public:
    FirstUnique(vector<int>& nums) {
        for(int num : nums)
            mp[num]++;
        for(int num : nums)
            if(mp[num] == 1)
                q.push(num);
    }
    
    int showFirstUnique() {
       while(!q.empty())
       {
           if(mp[q.front()] == 1)
               break;
           else
               q.pop();
       }
        
        return (q.size()==0)?-1:q.front();
    }
    
    void addToMap(int value)
    {
        mp[value]++;
        if(mp[value] == 1)
            q.push(value);
    }
    
    void add(int value) {
        addToMap(value);
    }
};

/**
 * Your FirstUnique object will be instantiated and called as such:
 * FirstUnique* obj = new FirstUnique(nums);
 * int param_1 = obj->showFirstUnique();
 * obj->add(value);
 */
