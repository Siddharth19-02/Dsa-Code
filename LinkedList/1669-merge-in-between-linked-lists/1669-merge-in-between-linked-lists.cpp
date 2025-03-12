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
    ListNode* mergeInBetween(ListNode* list1, int a, int b, ListNode* list2) {
        
        ListNode* prev = NULL;
        ListNode* head = list1;

        int i;
        for(i = 0;i<a;i++)
        {
            prev = head;
            head = head->next;
        }

        prev->next = list2;

        prev = NULL;
        ListNode* head2 = list2;
        while(head2)
        {
            prev = head2;
            head2 = head2->next;
        }

        for(;i<b;i++)
        {
            head = head->next;
        }

        prev->next = head->next;

        return list1;
    }
};
