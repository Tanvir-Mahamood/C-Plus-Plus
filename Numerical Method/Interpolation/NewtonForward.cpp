#include <bits/stdc++.h>
using namespace std;
#define nn  "\n"

long double p, m = 1;

long double get_p(int k)
{
    k--;
    long double ans = m*(p - k);
    m = ans;
    return ans;
}

int Fact(int n)
{
    if(n == 0) return 1;
    return n * Fact(n-1);
}


int main() {
    int n, i, j;
    long double  val_x, val_y, h, x, y;

    cout << "Number of Points:";
    cin >> n;

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
    p = (long double)(x - xx[0]) / h;

    for(j=1; j<n; j++) //table ready
    {
        for(i=0; i<n-1; i++)
        {
            grid[i][j] = grid[i+1][j-1] - grid[i][j-1];
        }
    }

    y = grid[0][0];
    for(i=1; i<n; i++) // formula of y
    {
         y += ((long double)get_p(i) / Fact(i) ) * grid[0][i];
    }
    cout << y << nn;

    return 0;
}

/*
4
1 24
3 120
5 336
7 720
*/





