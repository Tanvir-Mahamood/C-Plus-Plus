#include<bits/stdc++.h>
using namespace std;
int main()
{
    set<int> st1,st2;
    set<vector<int>> res;
    vector<int> temp,temp2;

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
        temp2=it;
        for(i=0;i<temp2.size();i++) cout<<temp2[i]<<" ";
        cout<<endl;
    }


    return 0;
}

