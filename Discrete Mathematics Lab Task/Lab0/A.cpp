#include<bits/stdc++.h>
using namespace std;

bool prime(int n)
{
    n=n-2;
    int i,flag=0;
    for(i=3;i*i<=n;i++)
    {
        if(n%i==0)
        {
            flag=1;
            break;
        }
    }
    if(flag==0) return true;  //prime
    else return false;       //not prime
}

int main()
{
    int n;
    bool flag;
    cin>>n;
    if(n==2 || n==3) cout<<"0\n";
    else
    {
        flag=prime(n);
        if(flag==true) cout<<"1\n";
        else cout<<"0\n";
    }

    return 0;
}

