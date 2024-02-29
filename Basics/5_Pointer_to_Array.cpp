#include<iostream>
#include<stdio.h>
using namespace std;
int main()
{
    int A[5]={2,4,8,7,45};
    int *p;
    p=A;     //no need to add ampus and for array
    //p=&A[0]  this is right

    for(int i=0;i<5;i++)
    cout<<p[i]<<endl;
    //p can act as name of the array
    return 0;
}