/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode() : val(0), next(nullptr) {}
 *     ListNode(int x) : val(x), next(nullptr) {}
 *     ListNode(int x, ListNode *next) : val(x), next(next) {}
 * };
 */
class Solution {
public:
    ListNode* reverseList(ListNode* head) 
    {
        
        ListNode* first = head;
        ListNode* second = NULL;
        ListNode* third = NULL;
        
        
        while(first)
        {
            third = second;
            second = first;
            
            first = first->next;
            
            second->next = third;
        }
        
        return second;
    }

    ListNode* middle(ListNode* head)
    {
        ListNode* first = head;
        ListNode* second = head;

        while(first->next and first->next->next)
        {
            first = first->next->next;
            second = second->next;
        }

        return second->next;
    }
    
    int pairSum(ListNode* head) {

        ListNode* middleElement = middle(head);
        middleElement = reverseList(middleElement);
        
        int sum = 0;

        while(head and middleElement)
        {
            int currentSum = head->val + middleElement->val;
            sum = max(sum, currentSum);

            head = head->next;
            middleElement = middleElement->next;
        }

        return sum;
    }
};
