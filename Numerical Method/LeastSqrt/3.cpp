//y = ab^x

/*
Linearization of non-linear equation.

Given a tabular data(values of x and y) for y = ab^x.
Fit these points(x,y).
Determine suitable values of a and b for the curve y = ab^x. Also calculate error.
*/
#include <bits/stdc++.h>
using namespace std;
#define nn  "\n"
#define ll  long long

int main() {
    //ios::sync_with_stdio(false);
    //cin.tie(0);
    cout << fixed << setprecision(7);
    long double sum_x = 0, sum_y = 0, sum_xx = 0, sum_xy = 0, det, a0, a1, cal_y, error, A0, A1;
    int m, i;
    cin >> m;
    vector<long double> xx(m), yy(m);
    vector<long double> XX(m), YY(m);
    for(i=0; i<m; i++)
    {
        cin >> xx[i] >> yy[i];
        XX[i] = xx[i];
        YY[i] = log(yy[i]);
    }

    //printing table:
    cout << "X             Y           Y=Log(y)           X^2            XY\n";
    for(i=0; i<m; i++)
    {
        cout << xx[i] << "   " << yy[i] << "    " << YY[i] << "     " << XX[i] * XX[i] << "  " << XX[i] * YY[i] << nn;
        sum_x += XX[i];
        sum_y += YY[i];
        sum_xx += (XX[i] * XX[i]);
        sum_xy += (XX[i] * YY[i]);
    }
    cout << "\nSum of X: " << sum_x << nn;
    cout << "Sum of Y  : " << sum_y << nn;
    cout << "Sum of X^2: " << sum_xx << nn;
    cout << "Sum of XY : " << sum_xy << nn << nn;

    det = (m * sum_xx) - (sum_x * sum_x); //cout << det << nn;

    A0 = (long double)((sum_y * sum_xx) - (sum_xy * sum_x)) / det;
    A1 = (long double)((m * sum_xy) - (sum_x * sum_y)) / det;
    cout << "A0 = " <<  A0 << " A1 = " << A1 << nn;
    a0 = exp(A0);
    a1 = exp(A1);
    cout << "a = " <<  a0 << " b = " << a1 << nn;

    cout << "\n Error Calculations:\n";
    cout << "X              Y          CalY           Error\n";
    for(i=0; i<m; i++)
    {
        cal_y = a0 * pow(a1, xx[i]);
        error = abs((long double)(yy[i] - cal_y) / yy[i]);
        cout << xx[i] << "  " << yy[i] << "  " << cal_y << "    " << error << nn;
    }


    return 0;
}

/*
5
1 2.473
3 6.722
5 18.274
7 49.673
9 135.026
*/


