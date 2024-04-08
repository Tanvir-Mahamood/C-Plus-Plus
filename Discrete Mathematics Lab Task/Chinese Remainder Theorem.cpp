//In the name of Allah, the Gracious, the Merciful
#include <bits/stdc++.h>
using namespace std;
#define nn  "\n"

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

    return s1;
}

int main() {

    int n ,a, m, i, M = 1, x = 0;
    cout << "How many congruence ?";
    cin >> n;

    int carry_a[n+1], carry_m[n+1], carry_M[n+1], carry_y[n+1];

    for(i=1; i<=n; i++)
    {
        cin >> a >> m;
        carry_a[i] = a;
        carry_m[i] = m;
        M *= m;
    }

    for(i=1; i<=n; i++) carry_M[i] = M / carry_m[i];

    for(i=1; i<=n; i++) carry_y[i] = inverseMod(carry_M[i], carry_m[i]);

    for(i=1; i<=n; i++) x += carry_a[i] * carry_M[i] * carry_y[i];

    x %= M;
    if(x < 0) x += M;

    cout << x << nn;

    return 0;
}



