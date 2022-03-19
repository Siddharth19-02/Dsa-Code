class FreqStack {
public:
    unordered_map<int,int>frequency;
    unordered_map<int,stack<int> >bin;
    int max_freq;
    FreqStack() {
        max_freq=0;
    }
    
    void push(int val) {
        frequency[val]++;
        max_freq = max(max_freq,frequency[val]);
        bin[frequency[val]].push(val);
    }
    
    int pop() {
        int curr = bin[max_freq].top();
        bin[max_freq].pop();
        frequency[curr]--;
        if(bin[max_freq].empty())
            max_freq--;
        
        return curr;
    }
};
