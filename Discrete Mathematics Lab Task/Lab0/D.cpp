#include<bits/stdc++.h>
using namespace std;

int main()
{
    int n,i;
    cin>>n;
    vector<int> vec(n);
    for(i=0;i<n;i++) cin>>vec[i];
    sort(vec.begin(),vec.end());
    unique(vec.begin(),vec.end());
    cout<<vec[1]<<"\n";
    return 0;
}

