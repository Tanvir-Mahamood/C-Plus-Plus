#include <bits/stdc++.h>
using namespace std;

int dis(int x1,int y1,int x2,int y2)
{
    int d=sqrt((y2-y1)*(y2-y1)+(x2-x1)*(x2-x1));
    return d;
}

int main()
{
    int i,j,n,x,y,minn=INT_MAX,d;
    int x1,y1,x2,y2;
    int ans1,ans2,ans3,ans4;
    cout<<"How many ponts?\n";
    cin>>n;
    vector<pair<int,int>> vec;
    for(i=0;i<n;i++)
    {
        cin>>x>>y;
        vec.push_back({x,y});
    }

    for(i=0;i<n-1;i++)
    {
        x1=vec[i].first;
        y1=vec[i].second;
        for(j=i+1;j<n;j++)
        {
            x2=vec[j].first;
            y2=vec[j].second;

            d=dis(x1,y1,x2,y2);
            if(d<minn)
            {
                minn=d;
                ans1=x1;
                ans2=y1;
                ans3=x2;
                ans4=y2;
            }
        }
    }
    cout<<"Closest pair:\n";
    cout<<ans1<<" "<<ans2<<endl;
    cout<<ans3<<" "<<ans4<<endl;

    return 0;
}

