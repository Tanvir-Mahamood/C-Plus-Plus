#include<bits/stdc++.h>
using namespace std;

void cartesian(set<int> st1,set<int> st2)
{
    for(auto it1: st1)
    {
        for(auto it2: st2)
        {
            cout<<"("<<it1<<","<<it2<<") ";
        }
    }
}

int main()
{
    set<int> st1,st2;

    int i,n1,n2,val;
    cout<<"Enter the size of set-1 : ";
    cin>>n1;
    cout<<"Enter elements:";
    for(i=0;i<n1;i++)
    {
        cin>>val;
        st1.insert(val);
    }

    cout<<"Enter the size of set-2 : ";
    cin>>n2;
    cout<<"Enter elements:";
    for(i=0;i<n2;i++)
    {
        cin>>val;
        st2.insert(val);
    }

    cout<<"A*B=\n";
    cartesian(st1,st2);
    cout<<endl<<endl;

    cout<<"B*A=\n";
    cartesian(st2,st1);

    if(st1==st2) cout<<"\n\nA*B == B*A\n";
    else cout<<"\n\nA*B != B*A\n";

    return 0;
}
