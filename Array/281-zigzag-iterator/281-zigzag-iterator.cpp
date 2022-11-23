class ZigzagIterator {
    bool first;
    int i;
    int j;
    int size;
    vector<int> va;
    vector<int> vb;
public:
    ZigzagIterator(vector<int>& v1, vector<int>& v2) {
        first = (v1.size())?true:false;
        i=0;
        j=0;
        size = v1.size() + v2.size();
        va = v1;
        vb = v2;
    }

    int next()
    {  
        if(first)
        {
            if(j!=vb.size())
                first = !first;
            int curr = va[i++];
            return curr;
        }
        else
        {
            if(i!=va.size())
                first = !first;
            int curr = vb[j++];
            return curr;
        }
    }

    bool hasNext() {
        return (i+j)<size;
    }
};

/**
 * Your ZigzagIterator object will be instantiated and called as such:
 * ZigzagIterator i(v1, v2);
 * while (i.hasNext()) cout << i.next();
 */
