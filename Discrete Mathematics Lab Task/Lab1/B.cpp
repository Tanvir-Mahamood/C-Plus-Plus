#include<bits/stdc++.h>
using namespace std;

int main()
{
    int i,c1,c2,c3;
    char cc;
    string key,msz;
    cin>>key>>msz;
    for(i=0;i<msz.size();i++)
    {
        c1=key[i];
        c2=msz[i];
        c3=c1^c2;
        c3=c3%26;
        cc=c3+96;
        cout<<cc;
    }
    return 0;
}
