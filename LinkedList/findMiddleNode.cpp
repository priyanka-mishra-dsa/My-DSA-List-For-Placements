class Solution {
public:
    ListNode* middleNode(ListNode* head) {
        //we can use slow and fast pointer techinque
        //to find middle node of linked list
        //slow pointer jisko point krega wahi middle node hoga
        ListNode*slow=head;
        ListNode*fast=head;
        while(fast!=NULL && fast->next!=NULL)
        {
            slow=slow->next;
            fast=fast->next->next;
        }
        return slow;
    }
};
