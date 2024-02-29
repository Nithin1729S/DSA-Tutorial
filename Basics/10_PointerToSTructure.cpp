#include<iostream>
using namespace std;

struct Rectangle
{
    /* data */
    int length;
    int breadth;
};

int main()
{
    Rectangle *p;
    p=(struct Rectangle *)malloc(sizeof(struct Rectangle));   //malloc function returns a pointer of type void so we type cast it 

    //p=new Rectangle;
    
    p->length=15;
    p->breadth=28;

    cout<<p->length<<endl;
    cout<<p->breadth<<endl;




    return 0;

}
