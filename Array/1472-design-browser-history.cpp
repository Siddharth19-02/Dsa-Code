class BrowserHistory {
    vector<string>vec;
    int count;
    int actual;
    public:
    BrowserHistory(string homepage) {
        vec.push_back(homepage);
        count=0;
        actual=0;
    }
    
    void visit(string url) {
        
        if(count==vec.size()-1)
        {
            vec.push_back(url);
            count++;
            actual++;
        }
        else
        {
            count++;
            vec[count] = url;
            actual=count;
        }
        
    }
    
    string back(int steps) {
        count -= steps;
        if(count>=0)
            return vec[count];
        else
        {
            count =0;
            return vec[0];
        }
    }
    
    string forward(int steps) {
        count += steps;
        if(count>actual)
        {
            count = actual;
            return vec[count];
        }
        else
            return vec[count];
    }
};

