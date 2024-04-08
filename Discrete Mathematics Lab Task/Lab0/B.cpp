#include<bits/stdc++.h>
using namespace std;

int main()
{
    int n,i;
    long long sum=0;
    cin>>n;
    for(i=1;i*i<=n;i++)
    {
        if(n%i==0)
        {
            sum+=i;
            if(n/i != i) sum+=(n/i);
        }
    }
    cout<<sum<<"\n";

    return 0;
}
