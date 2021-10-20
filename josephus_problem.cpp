#include <bits/stdc++.h>
using namespace std;

struct node
{
  int data;
  struct node *next;
};

node *newnode(int data)
{
    node *temp = new node;
    temp->data = data;
    temp->next = NULL;
}

void josephusproblem(int m,int n)
{
    node *head = newnode(1);
    node *prev = head;
    for(int i=2;i<=n;i++)
    {
        prev->next = newnode(i);
        prev = prev->next;

    }
    prev->next = head;

    node *ptr1,*ptr2;
    ptr1 = head;
    while(ptr1->next != ptr1)
    {
        int count = 1;
        while(count != m)
        {
            ptr2 = ptr1;
            ptr1 = ptr1->next;
            count++;
        }
        ptr2->next = ptr1->next;
        free(ptr1);
        ptr1 = ptr2->next;
    }
    cout<<"the last person remains is at position number : "<<ptr1->data;
}

int main()
{
    int m,n;
    cout<<"enter the number of peoples : ";
    cin>>n;
    cout<<"enter the number of peoples to be skipped : ";
    cin>>m;
    josephusproblem(m,n);

    return 0;
}

