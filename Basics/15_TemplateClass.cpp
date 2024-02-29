#include<stdio.h>
#include<stdlib.h>
#include<iostream>

using namespace std;

template<class T>
class Arithmetic
{   
    private:
        T a;
        T b;
    public:
        Arithmetic(T a,T b)
        {
            this->a=a;
            this->b=b;
        }
        T add()
        {
            T c;
            c=a+b;
            return c;
        }
        T sub()
        {
            T c=a+b;
            return c;
        }
};

int main()
{
    Arithmetic<float> ar(9.45,6.45);
    Arithmetic<int> arr(9.45,6.45);
    cout<<"Addition "<<ar.add()<<endl;
    cout<<"Addition "<<arr.add()<<endl;
    return 0;

}