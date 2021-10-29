//Problem Link - https://leetcode.com/problems/intersection-of-two-linked-lists/

//Solution - 4 different approaches

class Solution {
public:
    ListNode *getIntersectionNode(ListNode *headA, ListNode *headB) {
        //-------------------OPTIMAL SOLUTION 2------------------------
        if(headA==NULL || headB==NULL) return NULL;
        ListNode *a = headA;
        ListNode *b = headB;
        
        while(a!=b){
            if(a==NULL)
                a=headB;
            else
                a=a->next;
            if(b==NULL)
                b=headA;
            else
                b=b->next;
        }
        return a;
        
        
        //--------------------OPTIMAL SOLUTION 1------------------------
        
        // int lenA=0, lenB=0;
        // ListNode* temp = headA;
        // while(temp!=NULL){
        //     lenA++;
        //     temp=temp->next;
        // }
        // temp = headB;
        // while(temp!=NULL){
        //     lenB++;
        //     temp=temp->next;
        // }
        // int len = abs(lenA-lenB);
        // ListNode* tA = headA;
        // ListNode* tB = headB;
        // if(lenA>lenB){
        //     while(len>0){
        //         tA=tA->next;
        //         len--;
        //     }
        // }else{
        //     while(len>0){
        //         tB=tB->next;
        //         len--;
        //     }
        // }
        // while(tA!=NULL && tB!=NULL){
        //     if(tA==tB)
        //         return tA;
        //     tA=tA->next;
        //     tB=tB->next;
        // }
        // return tA;
        
        
        //-----------------------BETTER---------------------------
        
        // unordered_map<ListNode*, int> m;
        // while(headA!=NULL){
        //     m[headA]++;
        //     headA=headA->next;
        // }
        // while(headB!=NULL){
        //     if(m.find(headB)!=m.end())
        //         return headB;
        //     headB=headB->next;
        // }
        // return NULL;
        
        
        //---------------------BRUTE FORCE------------------------------
        
        // ListNode* tempA = headA;
        // while(tempA->next != NULL){
        //     ListNode* tempB = headB;
        //     while(tempB->next!=NULL){
        //         if(tempA->next == tempB->next)
        //             return tempA->next;
        //         tempB=tempB->next;
        //     }
        //     tempA=tempA->next;
        // }
        // return NULL;
    }
};
