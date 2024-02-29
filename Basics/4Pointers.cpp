#include<iostream>
#include<stdio.h>
using namespace std;
int main()
{
    int a=10;
    int *p; //star should be used at declaration and dereferencing
    p=&a;
    cout<<a<<endl;

    cout<<"using pointer  "<<p<<endl;//address will be printed
    cout<<"using pointer  "<<*p<<endl;  //dereferencing
    cout<<"using pointer  "<<&a<<endl;//address will be printed
    
    return 0;

}