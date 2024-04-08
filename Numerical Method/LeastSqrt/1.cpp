/*
Given a tabular data(values of x and y).
Fit these points(x,y) to a linear straight line. Y = a0 + a1.X .
Determine suitable values of a0 and a1 for the straight line. Also calculate error.
*/

#include <bits/stdc++.h>
using namespace std;
#define nn  "\n"
#define ll  long long

int main() {
    //ios::sync_with_stdio(false);
    //cin.tie(0);
    long double sum_x = 0, sum_y = 0, sum_xx = 0, sum_xy = 0, det, a0, a1, cal_y, error;
    int m, i;
    cin >> m;
    vector<long double> xx(m), yy(m);
    for(i=0; i<m; i++) cin >> xx[i] >> yy[i];

    //printing table:
    cout << "X  Y    X^2     XY\n";
    for(i=0; i<m; i++)
    {
        cout << xx[i] << "   " << yy[i] << "    " << xx[i] * xx[i] << "  " << xx[i] * yy[i] << nn;
        sum_x += xx[i];
        sum_y += yy[i];
        sum_xx += (xx[i] * xx[i]);
        sum_xy += (xx[i] * yy[i]);
    }
    cout << "\nSum of X: " << sum_x << nn;
    cout << "Sum of Y: " << sum_y << nn;
    cout << "Sum of X^2: " << sum_xx << nn;
    cout << "Sum of XY: " << sum_xy << nn << nn;

    det = (m * sum_xx) - (sum_x * sum_x); //cout << det << nn;

    a0 = (long double)((sum_y * sum_xx) - (sum_xy * sum_x)) / det;
    a1 = (long double)((m * sum_xy) - (sum_x * sum_y)) / det;
    cout << "a0 = " <<  a0 << "\na1 = " << a1 << nn;

    cout << "\n Error Calculations:\n";
    cout << "X  Y   CalY    Error\n";
    for(i=0; i<m; i++)
    {
        cal_y = a0 + a1 * xx[i];
        error = abs((long double)(yy[i] - cal_y) / yy[i]);
        cout << xx[i] << "  " << yy[i] << "  " << cal_y << "    " << error << nn;
    }


    return 0;
}

/*
4
0 -1
2 5
5 12
7 20
*/
