/*
7
1.0 2.7183
1.2 3.3201
1.4 4.0552
1.6 4.9530
1.8 6.0496
2.0 7.3891
2.2 9.0250
*/

/*
Given table of values of x & y. The function y=f(x) is unknown.
Determine first derivative of x (that is f'(x)), where x is a tabular value.

Sample input output:
Number of Points:7
1.0 2.7183
1.2 3.3201
1.4 4.0552
1.6 4.9530
1.8 6.0496
2.0 7.3891
2.2 9.0250
Enter desired value of x: 2
8.1795
*/

#include <bits/stdc++.h>
using namespace std;
#define nn  "\n"

int main() {
    int n, i, j, index = -1;
    long double  val_x, val_y, h, x, y = 0, val, sign;

    cout << "Number of Points:"; cin >> n;

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

    for(i=0; i<n; i++)
    {
        if(xx[i] == x)
        {
            index = i;
            break;
        }
    }
    h = xx[1] - xx[0]; //cout << index << nn;
    if(index == -1)
    {
        cout << "Out of table\n";
        return 0;
    }

    for(j=1; j<n; j++) //table ready
    {
        for(i=0; i<n-1; i++)
        {
            grid[i][j] = grid[i+1][j-1] - grid[i][j-1];
        }
    }

    for(i=1; i<n-index; i++)
    {
        val = ((long double) 1 / i) * grid[index][i]; //cout << val << " ";
        sign = (1 & i) ? 1 : -1;
        y += (val*sign);
    }
    y = ((long double) 1 / h) * y;
    cout << y << nn;

    return 0;
}







