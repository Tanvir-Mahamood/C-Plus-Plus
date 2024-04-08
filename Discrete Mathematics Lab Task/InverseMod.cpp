//In the name of Allah, the Gracious, the Merciful

#include <bits/stdc++.h>
using namespace std;

#define nn  "\n"
#define ll  long long
#define ull unsigned long long
#define yes cout<<"YES\n"
#define no  cout<<"NO\n"
int GCD, S, T;

int inverseMod(int a, int b)
{
    int q, r, s1, s2, s, t1, t2, t;

    s1 = 1; s2 = 0; t1 = 0; t2 = 1;

    while(b != 0)
    {
        q = a / b;
        r = a % b;

        s = s1 - q * s2;
        t = t1 - q * t2;

        a = b;
        b = r;

        s1 = s2;
        s2 = s;

        t1 = t2;
        t2 = t;
    }

    GCD = a; S = s1; T = t1; //to print gcd and Bezout Identity

    return s1;
}

int main() {
    int a, b, gcd, inv;

    cin >> a >> b;
    gcd = __gcd(a, b);
    inv = inverseMod(a, b);

    if(gcd == 1) cout << "Multiplicative Inverse of " << a << " mod " << b << " = " << inv << nn;
    else         cout << "There is no multiplicative inverse\n";

    cout << "GCD = " << GCD << nn;
    cout << "Bezout Identity: s = " << S << " and t = " << T << nn;

    return 0;
}




