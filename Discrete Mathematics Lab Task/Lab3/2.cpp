#include<bits/stdc++.h>
using namespace std;
int n;
int subset[100];
vector<int> a;

void generate_subset(int pos,int cnt)
{
    if(pos==n)
    {
        cout<<"{";
        for(int i=0;i<cnt;i++)
        {
            cout<<subset[i];
            if(i != cnt-1) cout<<",";
        }
        cout<<"}"<<endl;
        return;
    }
    generate_subset(pos+1,cnt);
    subset[cnt]=a[pos];
    generate_subset(pos+1,cnt+1);
}

int main()
{
    set<int> st;
    int i,val;
    cout<<"Enter the size of set : ";
    cin>>n;
    cout<<"Enter elements:";
    for(i=0;i<n;i++)
    {
        cin>>val;
        st.insert(val);
    }
    for(auto it: st) a.push_back(it);

    //cout<<"Power sets:\n{ }";
    generate_subset(0,0);


    return 0;
}
