//Problem Link - https://leetcode.com/problems/odd-even-linked-list/

//Solution  

class Solution {
public:
    ListNode* oddEvenList(ListNode* head) {
        if(head==NULL)
            return head;
        
        ListNode *oddPtr=head, *evenPtr=head->next, *evenHead=head->next;
        while(evenPtr && evenPtr->next && oddPtr && oddPtr->next){
            oddPtr->next = oddPtr->next->next;
            evenPtr->next = evenPtr->next->next;
            oddPtr = oddPtr->next;
            evenPtr = evenPtr->next;
        }
        oddPtr->next = evenHead;
        return head;
    }
};
