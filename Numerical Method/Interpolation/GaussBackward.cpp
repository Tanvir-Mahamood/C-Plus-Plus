#include <bits/stdc++.h>
using namespace std;
#define nn  "\n"

long double p, m = 1;

long double get_p(int k)
{
    k--;
    //long double ans = m*(p - k);
    long double ans = m*(p + k);
    m = ans;
    return ans;
}

int Fact(int n)
{
    if(n == 0) return 1;
    return n * Fact(n-1);
}


int main() {
    int n, i, j, midd;
    long double  val_x, val_y, h, x, y, term, factor;

    cout << "Number of Points:";
    cin >> n;
    midd = n / 2;

    long double xx[n];

    vector<vector<long double>> grid(n,vector<long double>(n));

    for(i=0; i<n; i++) //input complete
    {
        cin >> val_x >> val_y;
        xx[i] = val_x;
        grid[i][0] = val_y;
    }

    cout << "Enter desired value of x: ";
    cin >> x;

    h = xx[1] - xx[0];
    p = (long double)(x - xx[midd]) / h;

    for(j=1; j<n; j++) //table ready
    {
        for(i=0; i<n-1; i++)
        {
            grid[i][j] = grid[i+1][j-1] - grid[i][j-1];
        }
    }

    y = grid[midd][0];
    for(i=1; i<n; i++) // formula of y
    {
         factor = (long double)(p - 1) / (p + i - 1);
         term = ((long double)get_p(i) / Fact(i) ) * grid[(n-i-1)/2][i];
         if(i >=  3) term *= factor;
         y += term;
    }
    cout << y << nn;

    return 0;
}

/*
7
1 2.7183
1.05 2.8577
1.1 3.0042
1.15 3.1582
1.2 3.3201
1.25 3.4903
1.3 3.6693
*/








