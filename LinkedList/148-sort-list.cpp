
ListNode* merge(ListNode* head1,ListNode* head2)
{
    if(head1==NULL && head2==NULL)
    return head1;

    if(head1==NULL)
    return head2;

    if(head2==NULL)
    return head1;

    ListNode* head=NULL;
    ListNode* tail=NULL;

    if(head1->val<head2->val)
    {
        head=head1;
        tail=head1;
        head1=head1->next;
    }
    else
    {
        head=head2;
        tail=head2;
        head2=head2->next;
    }

    while(head1!=NULL && head2!=NULL)
    {
        if(head1->val<head2->val)
        {
            tail->next=head1;
            tail=head1;
            head1=head1->next;
        }
        else
        {
            tail->next=head2;
            tail=head2;
            head2=head2->next;
        }
    }

    if(head1!=NULL)
    {
        tail->next=head1;
        tail=head1;
        head1=head1->next;
    }

    if(head2!=NULL)
    {
        tail->next=head2;
        tail=head2;
        head2=head2->next;
    }
    return head;
}
ListNode* middle_element(ListNode* head)
{
    if(head==NULL||head->next==NULL)
    {
        return head;
    }


    ListNode* fir=head;
    ListNode* sec=head;

    while(fir->next!=NULL and fir->next->next!=NULL)
    {
         fir=fir->next->next;
         sec=sec->next;
    }

    ListNode* second=sec->next;

    sec->next=NULL;
    return second;
}


class Solution {
public:
    ListNode* sortList(ListNode* head) {
        if(head==NULL||head->next==NULL)
            return head;
            
        ListNode* head2 = middle_element(head);
        
        head = sortList(head);
        head2 = sortList(head2);
        return merge(head,head2);
    }
};
