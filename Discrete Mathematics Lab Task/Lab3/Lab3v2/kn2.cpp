#include<bits/stdc++.h>
using namespace std;
int main()
{
    int k;
    set<int> st1,st2;
    set<vector<int>> res,res2;
    vector<int> temp,temp2;

    cout<<"How many sets? ";
    cin>>k;

    int i,n1,n2,val,n;
    cout<<"Enter the size of set-1 : ";
    cin>>n1;
    cout<<"Enter elements:";
    for(i=0; i<n1; i++)
    {
        cin>>val;
        st1.insert(val);
    }

    cout<<"Enter the size of set-2 : ";
    cin>>n2;
    cout<<"Enter elements:";
    for(i=0; i<n2; i++)
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

    k=k-2;

    while(k--)
    {
        set<int> st3;
        cout<<"Enter the size of set-1 : ";
        cin>>n;
        cout<<"Enter elements:";
        for(i=0; i<n; i++)
        {
            cin>>val;
            st3.insert(val);
        }

        for(auto it1: res)
        {
            temp2=it1;
            for(auto it2: st3)
            {
                temp2.push_back(it2);
                res.insert(temp2);
                temp2.pop_back();
            }
        }
        res=res2;
    }

    for(auto it: res)
    {
        temp2=it;
        for(i=0;i<temp2.size();i++) cout<<temp2[i]<<" ";
        cout<<endl;
    }


    return 0;
}


