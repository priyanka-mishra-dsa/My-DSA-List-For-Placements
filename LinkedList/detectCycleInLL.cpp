class Solution {
public:
    bool hasCycle(ListNode *head) {
        //using slow and fast pointer
        ListNode*slow=head;
        ListNode*fast=head;
        while(fast!=NULL && fast->next!=NULL)
        {
            //move pointers
            slow=slow->next;
            fast=fast->next->next;
            if(slow==fast)
           {
            //cycle is present
            return true;
           }
        }
        return false;

    }

};
