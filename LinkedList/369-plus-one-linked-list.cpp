class Solution {
public:
    int plusOneAdd(ListNode* head)
    {
        if(head == NULL)
            return 1;
        
        int carry = plusOneAdd(head->next);
        
        int val = head->val + carry;
        carry = val/10;
        val = val%10;
            
        head->val = val;
        
        return carry;
    }
    
    ListNode* plusOne(ListNode* head) {
        
        int carry = plusOneAdd(head);
        
        if(carry)
        {
            ListNode* newNode = new ListNode(carry);
            newNode->next = head;
            head = newNode;
        }
        return head;
    }
};
