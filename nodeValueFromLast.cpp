/* struct Node {
  int data;
  struct Node *next;
  Node(int x) {
    data = x;
    next = NULL;
  }
};
*/

/* Should return data of n'th node from the end of linked list.
*  head: head of the linked list
*  n: nth node from end to find
*/
int getNthFromLast(Node *head, int n){
    int i=0;
    struct Node* count=NULL;
    count=head;
    
    for(i; count->next!=NULL; i++)
        count=count->next;
        
    if (n>i+1)
        return -1;
        
    for(int j=0; j<(i-n+1); j++)
        head=head->next;
    
    return head->data;
}
