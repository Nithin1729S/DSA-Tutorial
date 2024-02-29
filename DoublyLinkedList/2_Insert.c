#include<stdio.h>
#include<stdlib.h>
#include "1_basics.h"

int main()
{

    int A[5]={1,2,3,4,5};
    int n=5;
    struct Node* head1=NULL;
    create(&head1,A,n);
    display(head1);
    reverse(&head1);
    display(head1);
    return 0;
}
