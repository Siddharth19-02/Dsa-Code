class Node{
    public:
    int key;
    int value;
    Node* next;
    Node* prev;
    Node(int key,int value)
    {
        this->key = key;
        this->value = value;
    }
};

class LRUCache {
public:
    int size;
    Node* head = new Node(-1,-1);
    Node* tail = new Node(-1,-1);
    
    unordered_map<int,Node*>mp;
    
    LRUCache(int capacity) {
        size = capacity;
        mp.clear();
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
    }
    
    void deleteNode(Node* node)
    {
        Node* delPrev = node->prev;
        Node* delNext = node->next;
        
        delPrev->next = delNext;
        delNext->prev = delPrev;
    }
    
    int get(int key) {
        if(mp.find(key)==mp.end())
        {
            return -1;
        }
        else
        {
            Node* curr = mp[key];
            int x = curr->value;
            deleteNode(curr);
            addNode(curr);
            return x;
        }
    }
    
    void put(int key, int value) {
        if(mp.find(key)!=mp.end())
        {
            Node* curr = mp[key];
            mp.erase(key);
            deleteNode(curr);
        }
        else if(mp.size()==size)
        {
            Node* curr = tail->prev;
            int key = curr->key;
            mp.erase(key);
            deleteNode(curr);
        }
        Node* now = new Node(key,value);
        addNode(now);
        mp[key] = now;
    }
};

/**
 * Your LRUCache object will be instantiated and called as such:
 * LRUCache* obj = new LRUCache(capacity);
 * int param_1 = obj->get(key);
 * obj->put(key,value);
 */
