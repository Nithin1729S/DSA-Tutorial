#include<bits/stdc++.h>
using namespace std;

#define ll long long int
#define vi vector<int>
#define vll vector<long long int>


void reverseSort(vi &L)
{
    for(int i=0;i<L.size()-1;i++)
    {
        int m=*min_element(L.begin()+i,L.end());
        auto x=find(L.begin(),L.end(),m);
        reverse(L.begin()+i,x+1); //last index is exclusive
    }
}
int main()
{
    #ifndef ONLINE_JUDGE
        freopen("in.txt","r",stdin);
        freopen("out.txt","w",stdout);
    #endif

    std::ios::sync_with_stdio(false);

    int T;
    cin>>T;
    for(int c=0;c<T;c++)
    {
        int N;
        cin>>N;
        vi L;
        for(int i=0;i<N;i++)
        {
            int num;
            cin>>num;
            L.push_back(num);
        }
        reverseSort(L);
        for(int i=0;i<N;i++)
        {
            cout<<L[i]<<" ";
        }
        cout<<"\n";
        
        

    }
}

