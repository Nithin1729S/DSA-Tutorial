#include<iostream>
#include<stdio.h>
#include<stdlib.h>
using namespace std;
int main()
{
    int *p;
   // p=(int*)malloc(5*sizeof(int));  C style
    p=new int[5];  //c++ style..Dynamically allots memeroy in heap and must be freed at the end
    p[0]=10;p[1]=13;p[2]=34;p[3]=67;p[4]=88;

    for(int i=0;i<5;i++)
    cout<<p[i]<<endl;

    delete [ ] p;   //heap memory deallocated
    //free(p);  c style
    return 0;
}