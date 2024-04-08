#include<bits/stdc++.h>
using namespace std;
int main()
{
    set<int> st1,st2,st3,st4;
    map<int,int> mp;

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

    cout<<"Size of Set-1 = "<<st1.size()<<endl;
    cout<<"Size of Set-2 = "<<st2.size()<<endl<<endl;

    if(st1==st2) cout<<"Two sets are Equal\n\n";
    else cout<<"Two sets are not equal\n\n";

    cout<<"Union of two sets: ";
    st3=st1;
    for(auto it: st2) st3.insert(it);
    for(auto it: st3) cout<<it<<" ";
    cout<<endl<<endl;;

    cout<<"Intersection of two sets: ";
    for(auto it: st1) mp[it]++;
    for(auto it: st2) mp[it]++;
    for(auto it: mp) if(it.second==2) st4.insert(it.first);
    for(auto it: st4) cout<<it<<" ";
    cout<<endl<<endl;

    return 0;
}

