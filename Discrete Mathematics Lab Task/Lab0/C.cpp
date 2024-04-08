#include<bits/stdc++.h>
using namespace std;

int GCD(int a,int b)
{
    if(b==0) return a;
    else return GCD(b,a%b);
}


int main()
{
    int n1,n2,gg,ll;
    cin>>n1>>n2;

    gg=GCD(n1,n2);
    ll=(n1*n2)/gg;

    cout<<gg<<" "<<ll<<"\n";

    return 0;
}
