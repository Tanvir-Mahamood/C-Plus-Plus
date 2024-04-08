#include <bits/stdc++.h>
using namespace std;

int mincoins(int n,int coins[],int T,int dp[])
{
    for(int i=1;i<=n;i++)
    {
        dp[i]=INT_MAX;
        for(int j=0;j<T;j++)
        {
            if(i-coins[j]>=0)
            {
                int subprob=dp[i-coins[j]];
                dp[i]=min(dp[i],subprob+1);
            }
        }
    }
    return dp[n];
}

int main() {
    int n,T;
    cout<<"Enter the mount of money:";
    cin>>n;
    cout<<"Enter the the number of coins:";
    cin>>T;

    int coins[T];
    cout<<"The coins are: ";
    for(int i=0;i<T;i++) cin>>coins[i];
    int dp[100]={0};

    cout<<"Minimum Coin: "<<mincoins(n,coins,T,dp)<<endl;

    return 0;
}





