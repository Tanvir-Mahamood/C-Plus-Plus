#include<bits/stdc++.h>
using namespace std;
int main()
{
    int k;
    set<int> st1;
    set<vector<int>> res,res2;
    vector<int> temp;

    cout<<"How many sets? ";
    cin>>k;

    int i,n,val;
    cout<<"Enter the size of set-1 : ";
    cin>>n;
    cout<<"Enter elements:";
    for(i=0; i<n; i++)
    {
        cin>>val;
        temp.push_back(val);
        res.insert(temp);
        temp.clear();
    }

    k=k-1;

    while(k--)
    {
        set<int> st2;
        cout<<"Enter the size of set-2 : ";
        cin>>n;
        cout<<"Enter elements:";
        for(i=0; i<n; i++)
        {
            cin>>val;
            st2.insert(val);
        }

        for(auto it1: res)
        {
            temp=it1;
            for(auto it2: st2)
            {
                temp.push_back(it2);
                res2.insert(temp);
                temp.pop_back();
            }
        }
        res=res2;
        res2.clear();
    }

    for(auto it: res)
    {
        temp=it;
        for(i=0;i<temp.size();i++) cout<<temp[i]<<" ";
        cout<<endl;
    }


    return 0;
}




