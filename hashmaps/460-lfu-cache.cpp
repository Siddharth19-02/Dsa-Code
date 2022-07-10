class Node{
    public:
    int key;
    int value;
    int count;
    Node* next;
    Node* prev;
    Node(int key,int value)
    {
        this->key = key;
        this->value = value;
        count = 1;
    }
};

class List{
    public:
    int size;
    Node* head;
    Node* tail;
    
    List() {
        size = 0;
         head = new Node(-1,-1);
        tail = new Node(-1,-1);
        head->next = tail;
        tail->prev = head;
    }
    
    void addNode(Node* node)
    {
        Node* first = head->next;
        node->next = first;
        node->prev = head;
        
        head->next = node;
        first->prev = node;
        size++;
    }
    
    void deleteNode(Node* node)
    {
        Node* delPrev = node->prev;
        Node* delNext = node->next;
        
        delPrev->next = delNext;
        delNext->prev = delPrev;
        size--;
    }
    
};
class LFUCache {
    public:
    unordered_map<int,Node*>mp;
    unordered_map<int,List*>freq;
    int minFreq;
    int currSize;
    int size;
    LFUCache(int capacity)
    {
        size = capacity;
        currSize = 0;
        minFreq = 0;
    }
    
    void updateFreqMap(Node* curr)
    {
        int count = curr->count;
        List* now = freq[count];
        
        now->deleteNode(curr);
        
        if(count == minFreq and now->size==0)
        {
            minFreq++;
        }
        
        curr->count = count + 1;
        
        List* newList = new List();
        if(freq.find(count+1)!=freq.end())
            newList = freq[count+1];
        
        newList->addNode(curr);
        freq[curr->count] = newList;
        mp[curr->key] = curr;
    }
    
    int get(int key) {
        if(mp.find(key)==mp.end())
            return -1;
        
        cout<<key<<" ";
        Node* now = mp[key];
        int value = now->value;
        updateFreqMap(now);
        return value;
    }
    
    void put(int key, int value) {
        if(size==0)
            return;
        if(mp.find(key)!=mp.end())
        {
            Node* curr = mp[key];
            curr->value = value;
            updateFreqMap(curr);
        }
        else
        {
            if(currSize == size)
            {
                List* curr = freq[minFreq];
                Node* now = curr->tail->prev;
                curr->deleteNode(now);
                mp.erase(now->key);
                currSize--;
            }
            
            currSize++;
            minFreq = 1;
            
            Node* node = new Node(key,value);
            
            List* list = new List();
            if(freq.find(1)!=freq.end())
            {
                list = freq[1];
            }
            
            list->addNode(node);
            freq[1] = list;
            mp[key] = node;
        }
        
    }
};
