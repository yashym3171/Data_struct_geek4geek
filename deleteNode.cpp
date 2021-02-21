/* Link list Node 
struct Node
{
    int data;
    struct Node* next;
    
    Node(int x){
        data = x;
        next = NULL;
    }
};
*/

/*You are required to complete below method*/
Node* deleteNode(Node *head,int x){
    struct Node* current=new Node(0);
    current=head;
    
    if(x==1)
        return head->next;
        
    for(int i=1; i<x-1; i++){
        current=current->next;
    }
    current->next = current->next->next;
    
    return head;
}