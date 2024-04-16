// From 21:37 to 09:37 PM

#include <bits/stdc++.h>
using namespace std;

#define nn     "\n"
#define ll     long long
#define ull    unsigned long long
#define yes    cout<<"YES\n"
#define no     cout<<"NO\n"
#define fastio ios::sync_with_stdio(false); cin.tie(NULL)
#define mod    1000000007
#define PI     3.141592653589793238462

void solve()
{
    string tim;
    cin >> tim;
    int hours = (tim[0]-48) * 10 + (tim[1]-48);
    if(hours == 0) cout << 12 << ":" << tim[3] << tim[4] << " AM\n";
    else if(hours <= 11) cout << tim << " AM\n";
    else if(hours == 12) cout << tim << " PM\n";
    else if(hours <= 21) cout << '0' << hours - 12 << ":" << tim[3] << tim[4] << " PM\n";
    else cout << hours - 12 << ":" << tim[3] << tim[4] << " PM\n";
}

int main() {
    fastio;
    int t = 1;
    cin >> t;
    for(int i=1;i<=t;i++)
    {
        //cout << "Case " << i << ": \n";
        solve();
    }

    return 0;
}



