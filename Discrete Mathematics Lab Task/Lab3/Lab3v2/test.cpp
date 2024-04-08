#include<bits/stdc++.h>
using namespace std;

cartesian(set<int> st1,set<int> st2)
{
    vector<int> temp;
    set<vector<int>> res;

    for(auto it1: st1)
    {
        for(auto it2: st2)
        {
            temp.push_back(it1);
            temp.push_back(it2);
            res.insert(temp);
            temp.clear();
        }
    }

    for(auto it: res)
    {
        temp=it;
        for(int i=0;i<temp.size();i++) cout<<temp[i]<<" ";
        cout<<endl;
    }
}

int main()
{
    set<int> st1,st2,set12,set21;
    set<vector<int>> res;
    vector<int> temp;

    int i,n,val;
    cout<<"Enter the size of set-1 : ";
    cin>>n;
    cout<<"Enter elements:";
    for(i=0;i<n;i++)
    {
        cin>>val;
        st1.insert(val);
    }

    cout<<"Enter the size of set-2 : ";
    cin>>n;
    cout<<"Enter elements:";
    for(i=0;i<n;i++)
    {
        cin>>val;
        st2.insert(val);
    }

    cout<<"A*B=\n";
    cartesian(st1,st2);
    cout<<endl<<endl;

    cout<<"B*A=\n";
    cartesian(st2,st1);



    /*for(auto it1: st1)
    {
        for(auto it2: st2)
        {
            temp.push_back(it1);
            temp.push_back(it2);
            res.insert(temp);
            temp.clear();
        }
    }

    for(auto it: res)
    {
        temp=it;
        for(i=0;i<temp.size();i++) cout<<temp[i]<<" ";
        cout<<endl;
    }*/


    return 0;
}

