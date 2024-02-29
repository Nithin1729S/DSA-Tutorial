#include<iostream>
using namespace std;
int main ()
{
    int a=10;
    int &r=a;
    cout<<a<<endl;
    r++;
    cout<<a<<" "<<r<<endl;
    int b=60;
    r=b;
    cout<<a<<endl;

}