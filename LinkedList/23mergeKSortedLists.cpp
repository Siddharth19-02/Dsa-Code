struct compare{
    bool operator()(ListNode* a,ListNode* b)
    {
        return a->val>b->val;
    }
};
    
class Solution {
public:
    
    
    ListNode* mergeKLists(vector<ListNode*>& lists) {
        
        priority_queue<ListNode*,vector<ListNode*>,compare >pq;
        
        if(lists.size()==0)
            return NULL;
        
        for(int i=0;i<lists.size();i++)
        {
            if(lists[i])
                pq.push(lists[i]);
        }
        
        if(pq.empty())
        {
            return NULL;
        }
        
        ListNode* head = NULL;
        ListNode* tail = NULL;
        
        
        ListNode* now = pq.top();
        pq.pop();
        if(now->next)
        {
            pq.push(now->next);
        }
        head = now;
        tail = now;
        
        while(!pq.empty())
        {
            ListNode* now = pq.top();
            pq.pop();
            if(now->next)
            {
                pq.push(now->next);
            }
            tail->next = now;
            tail = tail->next;
        }
        return head;
    }
};
