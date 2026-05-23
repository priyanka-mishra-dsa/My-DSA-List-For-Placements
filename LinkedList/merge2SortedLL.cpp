class Solution {
public:
    ListNode* mergeTwoLists(ListNode* list1, ListNode* list2) {
        ListNode*dummy=new ListNode(0);
        ListNode*temp=dummy;
        while(list1!=NULL && list2!=NULL)
        {
            //jiske value choti hogi phle wahi new LL me ayega
            if(list1->val<=list2->val)
            {
                temp->next=list1;
                list1=list1->next;
            }
            else if(list2->val<list1->val)
            {
                temp->next=list2;
                list2=list2->next;
            }
            //move temp for next value
            temp=temp->next;
        }
        //if nodes left in list 1
        if(list1!=NULL)
        {
            temp->next=list1;
        }
        else if(list2!=NULL)
        {
            temp->next=list2;
        }
        return dummy->next;  
    }
};
