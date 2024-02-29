#include<iostream>
using namespace std;

struct Rectangle
{
    int lenght;
    int breadth;
};


int main()
{

    struct Rectangle r{10,5}; //you can skip struct in c++
    cout<<r.lenght<<endl;
    cout<<r.breadth<<endl;

    Rectangle *p{&r};
    cout<<p->lenght<<endl;
    cout<<p->breadth<<endl;

    


}