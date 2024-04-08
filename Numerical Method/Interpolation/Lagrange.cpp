#include <bits/stdc++.h>
using namespace std;
#define nn  "\n"

int main() {
    int n, i, j;
    long double  val_x, val_y, h, x, y = 0, term, lob, hor;

    cout << "Number of Points:";
    cin >> n;

    long double xx[n];
    long double yy[n];

    for(i=0; i<n; i++) //input complete
    {
        cin >> val_x >> val_y;
        xx[i] = val_x;
        yy[i] = val_y;
    }

    cout << "Enter desired value of x: ";
    cin >> x;

    for(i=0; i<n; i++)
    {
        lob = hor = 1;
        for(j=0; j<n; j++)
        {
            if(i == j) continue;
            lob *= (x - xx[j]);
            hor *= (xx[i] - xx[j]);
        }
        term = (long double)lob / hor * yy[i];
        y += term;
    }
    cout << y << nn;
    return 0;
}

/*
4
300 2.4771
304 2.4829
305 2.4843
307 2.4871
*/







