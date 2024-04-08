/*
Given a number. If it is prime, it return its, otherwise return its next prime
*/
#include <bits/stdc++.h>
using namespace std;

int isprime(int a)
{
    int i,flag=0;
    for(i=2; i<=a/2; i++)
    {
        if(a%i==0)
        {
            flag=1;
            break;
        }
    }
    if(flag==0) return 1;
    else return 0;
}

int nextprime(int n)
{
    int m;
    m=isprime(n);
    if(m==1) return n;
    else
    {
        n++;
        return nextprime(n);
    }
}

int main()
{
    int n;
    cin>>n;
    int ans=nextprime(n);
    cout<<ans<<endl;

    return 0;
}
