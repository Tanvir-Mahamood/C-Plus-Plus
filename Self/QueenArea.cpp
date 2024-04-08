/*
Enter the order of Chess Board.
say 8X8, just input 8.
Sample test case:

16
2 2
1 1 1 0 0 0 0 0 0 0 0 0 0 0 0 0
1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1
1 1 1 0 0 0 0 0 0 0 0 0 0 0 0 0
0 1 0 1 0 0 0 0 0 0 0 0 0 0 0 0
0 1 0 0 1 0 0 0 0 0 0 0 0 0 0 0
0 1 0 0 0 1 0 0 0 0 0 0 0 0 0 0
0 1 0 0 0 0 1 0 0 0 0 0 0 0 0 0
0 1 0 0 0 0 0 1 0 0 0 0 0 0 0 0
0 1 0 0 0 0 0 0 1 0 0 0 0 0 0 0
0 1 0 0 0 0 0 0 0 1 0 0 0 0 0 0
0 1 0 0 0 0 0 0 0 0 1 0 0 0 0 0
0 1 0 0 0 0 0 0 0 0 0 1 0 0 0 0
0 1 0 0 0 0 0 0 0 0 0 0 1 0 0 0
0 1 0 0 0 0 0 0 0 0 0 0 0 1 0 0
0 1 0 0 0 0 0 0 0 0 0 0 0 0 1 0
0 1 0 0 0 0 0 0 0 0 0 0 0 0 0 1

It has returned a 2d matrix representing queen's attackable positions
*/
#include <bits/stdc++.h>
using namespace std;

#define nn "\n"
#define ll long long
#define ull unsigned long long
#define yes cout<<"YES\n"
#define no cout<<"NO\n"

int vis[100][100];

void solve()
{
    int n,x,y,s,i,j;
    cin>>n;
    cin>>x>>y;
    for(i=1;i<=n;i++)
    {
        vis[i][y]=1;
        vis[x][i]=1;
    }
    i=x;
    j=y;
    while(i<=n && j<=n && i>0 && j>0)
    {
        vis[i][j]=1;
        i++;
        j++;
    }
    i=x;
    j=y;
    while(i<=n && j<=n && i>0 && j>0)
    {
        vis[i][j]=1;
        i--;
        j--;
    }

    i=x;
    j=y;
    while(i<=n && j<=n && i>0 && j>0)
    {
        vis[i][j]=1;
        i--;
        j++;
    }
    i=x;
    j=y;
    while(i<=n && j<=n && i>0 && j>0)
    {
        vis[i][j]=1;
        i++;
        j--;
    }

    for(i=1;i<=n;i++)
    {
        for(j=1;j<=n;j++)
        {
            cout<<vis[i][j]<<" ";
        }
        cout<<nn;
    }
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    //ll t; cin>>t; while(t--)
    solve();

    return 0;
}




