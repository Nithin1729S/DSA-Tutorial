#include <iostream>
#include <stdio.h>
using namespace std;
int main()
{
    int n;
    cout << "Enter the size of the array:" << endl;
    cin >> n;
    int A[n]; // You cant initialize a variable array
    A[0] = 2; // except 2 rest of the values will be garbage

    for (int x : A)
    {
        cout << x << endl;
    }
}
