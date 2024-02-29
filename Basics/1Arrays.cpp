#include<iostream>
#include<stdio.h>
using namespace std;
int main()
{
    int A[8]={2,4,7,8,90};  //You can skip 5 next to A and the size will be set automatically
    //The 6th element of this array will be zero by default 
    int b[10]={0}; //initialized all the array elements to zero
    cout<<sizeof(A)<<endl;  //integer occupy 4 bits
    cout<<A[1]<<endl;
    printf("%d\n",A[2]);

    for(int i=0;i<10;i++)  //to access all the element s of the array
    {
        cout<<A[i]<<endl;


    }

    for (int x:A)   //For each loop
    {
        cout<<x<<endl;
    }

    






    return 0;

}

