#include<stdio.h>

void insert(int H[],int n)
{
    int i=n;
    int temp=H[i];

    while(i>1&&temp>H[i/2])
    {
        H[i]=H[i/2];
        i=i/2;
    }
    H[i]=temp;
}

void swap(int *a,int *b)
{
    int temp=*a;
    *a=*b;
    *b=temp;
}

int delete(int H[],int n)
{
    int i,j,x,val;
    val=H[1];
    x=H[n];
    H[1]=x;
    H[n]=val;  //keeping deleted value at last place
    i=1;
    j=2*i;
    while(j<n-1)
    {
        if(H[j+1]>H[j]) j=j+1;
        if(H[j]>H[i]) 
        {
            swap(&H[i],&H[j]);
            i=j;
            j=2*j;
        }
        else break;
    }
    return val;
}

int main()
{
    //ignore 0 here
    int H[]={0,2,5,8,9,4,10,7};
    for(int i=2;i<=7;i++)
        insert(H,i);

    // printf("Deleted Value is %d\n",delete(H,7));
    // printf("Deleted Value is %d\n",delete(H,6));
    for(int i=7;i>1;i--) delete(H,i);    //heap sort
    for(int i=1;i<=7;i++)
        printf("%d ",H[i]);
    printf("\n");
    return 0;
}