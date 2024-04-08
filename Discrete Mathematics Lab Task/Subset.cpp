//In the name of Allah, the Gracious, the Merciful

#include <bits/stdc++.h>
using namespace std;

#define nn  "\n"
#define ll  long long
#define ull unsigned long long
#define yes cout<<"YES\n"
#define no  cout<<"NO\n"

#define SetBit(x,k)   (x |= (1LL << k))    //set 1 to k-th bit of x
#define ClearBit(x,k) (x &= ~(1LL << k))   //set 0 to k-th bit of x
#define CheckBit(x,k) ((x>>k)&1)           //check if it is 1 or 0 in k-th bit of x


void solve()
{
    int n, i, j;
    cin >> n;

    int arr[n];
    for(i=0; i<n; i++) cin >> arr[i];


    for(i=0; i<(1<<n); i++) //iterating binary numbers from 0 to 2^n
    {
        for(j=0; j<n; j++) //position
        {
            if(CheckBit(i,j)) cout << arr[j] << " ";
        }
        cout << nn;
    }

}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    //ll t; cin>>t; while(t--)
    solve();

    return 0;
}





