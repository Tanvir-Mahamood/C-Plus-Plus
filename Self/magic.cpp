// Definition : https://en.wikipedia.org/wiki/Magic_square
// Magic Square Matrix  Generator.
/*
5

17 24 1 8 15
23 5 7 14 16
4 6 13 20 22
10 12 19 21 3
11 18 25 2 9

Sum of each row, each column and each diagonal are equal to 65
*/
#include <bits/stdc++.h>
using namespace std;
int a[15][15];

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    int n,i,j,cnt=1,last;
    cin>>n;
    i=1;
    j=n/2+1;
    last=n*n;
    while(cnt<=last)
    {
        if(i==1 && j==n)
        {
            a[i][j]=cnt;
            cnt++;
            i=i+1;
        }
        if(a[i][j]==0)
        {
            a[i][j]=cnt;
            cnt++;
            i--;
            j++;
        }
        else
        {
            i=i+2;
            j=j-1;
            a[i][j]=cnt;
            cnt++;
            i--;
            j++;
        }
        if(i==0) i=n;
        if(j>n) j=j%n;

    }

    for(i=1;i<=n;i++)
    {
        for(j=1;j<=n;j++)
        {
            cout<<a[i][j]<<" ";
        }
        cout<<"\n";
    }

    return 0;
}

