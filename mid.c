#include<stdio.h>
int a,b;
int checkSorted(int X[],int n);         //function declaration(to check whether the array taken is in increasing order or not)

void combine(int X[],int Y[], int C[]);     //function declaration(merges the elements in the arrays pointed by X and Y)


void main()              //main function
{
    
    printf("Enter the size of array A\n");
    scanf("%d",&a);
    printf("Enter the size of array B\n");
    scanf("%d",&b);
    if (a>0 &&b>0)
    {
        int ch=0;
        int A[a],B[b],C[a+b];
        while(ch==0)
        {
            printf ("Enter the elements of array A\n");
            for(int i=0;i<a;i++)
                scanf("%d",&A[i]);
            printf ("Enter the elements of array B\n");
            for(int i=0;i<b;i++)
            scanf("%d",&B[i]);
            int u=checkSorted(A,a);           //calling function checkSorted()
            int v=checkSorted(B,b);          //calling function checkSorted()
            
            if(u==1&&v==1)
            {
                combine(A,B,C);           //calling function combine()
                ch=1;
            }
            else
            {
                printf("Array is not sorted.\n");
                printf("Re-enter sorted Arrays.\n");
                ch=0;
            }
        }
        
        
        printf("Array C = ");
        for(int i=0;i<(a+b);i++)
            printf("%d ",C[i]);
    }
    
     if(a<=0 || b<=0)
    {
        printf("Please provide valid size.\n");
    }
    
    else
        printf("user given Negative size of array \n");
}

int checkSorted(int X[],int n)       //function definition
{
    int k=1;
    for(int i=0;i<n-1;i++)
    {
        if(X[i]>X[i+1])
        k=0;
    }
    
    return k;
}

void combine(int X[], int Y[], int C[])         //function definition
{
    int i = 0;
    int j = 0;
    int k=0;
 
        while (i < a && j < b) 
        {
            if (X[i] < Y[j]) 
            {
                C[k] = X[i];
                i++;
            }
 
            else 
            {
                C[k] = Y[j];
                j++;
            }
            k++;
        }
 
        if (i >= a) 
        {
            while (j < b) 
            {
                C[k] = Y[j];
                j++;
                k++;
            }
        }
 
        if (j >= b) 
        {
            while (i < a)
            {
                C[k] = X[i];
                i++;
                k++;
            }
        }
}
