//In the name of Allah, the Gracious, the Merciful

#include <bits/stdc++.h>
using namespace std;
#define nn  "\n"
#define ll  long long
int N;

bool check(int n,int i)
{
    if(( (n>>i) & 1 ) != 0) return true;  //Set
    else                    return false; //Not Set
}

int FastBigMod(int b, int p, int m)
{
    if(b == 0) return 0;
    if(p == 0) return 1;
    int val = b;
    for(int i=N-2; i>=0; i--)
    {
        bool ans = check(p,i);

        if(ans)
        {
            val = (val * val) % m;
            val = (val * b) % m;
            //cout << "set ";
        }
        else
        {
            val = (val * val) % m;
            //cout << "not ";
        }
    }
    return val;
}

int main() {
    int base, power, mod, ans;

    cin >> base >> power >> mod;

    N = ceil((double)log(power) / log(2)); //cout << N << nn;

    ans = FastBigMod(base, power, mod);
    cout << ans << nn;

    return 0;
}






