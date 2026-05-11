class Solution {
public:
    ListNode* deleteMiddle(ListNode* head) {
        if(head==NULL ||head->next==NULL)
        return NULL;
        //using slow and fast pointer find middle node
        //delete middle node
        //for deleting middle node we have to track slow pointer ke phle wale node
        ListNode*slow=head;
        ListNode*fast=head;
        ListNode*prevSlow=NULL;
        while(fast!=NULL && fast->next!=NULL)
        {
            prevSlow=slow;
            slow=slow->next;
            fast=fast->next->next;
        }
        prevSlow->next=slow->next;
        delete(slow);
        return head;
        
    }
};
