#include<iostream>
#include<stdio.h> //THis is a c preprocessor usign this here will enable the use of c style coding
using namespace std;

struct Rectangle
{
    int length;
    int breadth;
    char x;
//there are   two members in this structure
}r1,r2;//this is just a definiotn of sturcture and doesnt consume any memory

// struct Rectangle r1,r2; now this is globally declared


int main()
{
    //struct Rectangle r1;//this is locally declared only inside the main function
    //Variable decleartion can be done inside the definition as shown above.

    struct Rectangle r1={10,5};
    printf("%llu",sizeof(r1));

    r1.length=15;   //dot operator is used to access the members of structures.

    r1.breadth=24;

    cout<<r1.length<<endl;
    cout<<r1.breadth<<endl;

    return 0;











}