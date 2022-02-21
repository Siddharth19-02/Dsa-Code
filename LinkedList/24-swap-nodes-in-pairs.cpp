class Solution {
public:
    ListNode* swapPairs(ListNode* head) {
        if(head==NULL)
            return NULL;
        if(head->next==NULL)
            return head;
        
        ListNode* curr = head;
        ListNode* prev = NULL;

        while(curr and curr->next)
        {
            ListNode* curr2 = curr->next;
            ListNode* tar = curr2->next;

            if(curr==head)
            {
                head = curr2;
            }
            else
            {
                prev->next = curr2;
            }

            curr->next = tar;
            curr2->next= curr;

            prev = curr;
            curr = tar;

        }
        return head;
        
    }
};
