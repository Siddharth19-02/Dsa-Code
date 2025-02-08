class NumberContainers {
    unordered_map<int,int>indexToNumber;
    unordered_map<int, priority_queue<int, vector<int>, greater<int> >>numberToIndex;
public:
    NumberContainers() {
        
    }
    
    void change(int index, int number) {
        indexToNumber[index] = number;
        numberToIndex[number].push(index);
    }
    
    int find(int number) {
        
        if(numberToIndex.find(number) == numberToIndex.end())
            return -1;

        auto &pq = numberToIndex[number];

        while(!pq.empty())
        {
            int index = pq.top();
            if(indexToNumber[index] == number)
            {
                return index;
            }
            pq.pop();

        }

        return -1;
    }
};

/**
 * Your NumberContainers object will be instantiated and called as such:
 * NumberContainers* obj = new NumberContainers();
 * obj->change(index,number);
 * int param_2 = obj->find(number);
 */
