/*
Given table of values of x and y, where y = f(x) is unknown.
Determine Integration of y for the  data from table.

Sample Input Output: Example 6.10 from the book Numerical Analysis by Sastry.
How many points ?9
0 1
0.125 0.8889
0.250 0.8000
0.375 0.7273
0.5 0.66667
0.625 0.6154
0.750 0.5714
0.875 0.5333
1.0 0.5
Menu
   1. Trapezoidal Rule
   2. Simpson's 1/3
   3. Simpson's 3/8
 0. Exit

Enter choice: 1
   1. Trapezoidal Rule
   Answer: 0.694121

Enter choice: 2
   2. Simpson's 1/3
   Answer: 0.693156

Enter choice: 3
   3. Simpson's 3/8
   Answer: 0.684854

Enter choice: 0
*/

#include <bits/stdc++.h>
using namespace std;

#define nn  "\n"
#define ll  long long
#define ull unsigned long long
#define yes cout<<"YES\n"
#define no  cout<<"NO\n"
#define mod 1000000007

int main() {
    long double u, l, h, n,i, ans = 0, val1, val2; int j, num;
    vector<string> menu {"   1. Trapezoidal Rule", "   2. Simpson's 1/3", "   3. Simpson's 3/8", " 0. Exit"};

    cout << "How many points ?"; cin >> num;
    vector<long double> xx, yy;
    for(j=0; j<num; j++)
    {
        cin >> val1 >> val2;
        xx.push_back(val1);
        yy.push_back(val2);
    }

    h = xx[1] - xx[0];

    cout << "Menu\n";
    for(i=0; i<menu.size(); i++) cout << menu[i] << nn;
    cout << nn;

    int t = 100, choice;
    while(t != 0)
    {
        cout << "Enter choice: ";
        cin >> t;

        if(t) cout << menu[t-1]<< nn;;
        if(t == 1)
        {
            ans = 0;
            for(i=1; i<yy.size()-1; i++)
            {
                ans += yy[i];
            }
            ans =ans * 2;
            ans += yy.front() + yy.back();
            ans = ans * ((long double)h / 2);
            cout << "   Answer: " << ans << nn;
        }
        else if(t == 2)
        {
            ans = 0;
            for(i=1; i<yy.size()-1; i+=2)
            {
                ans += (4 * yy[i]);
            }
            for(i=2; i<yy.size()-1; i+=2)
            {
                ans += (2 * yy[i]);
            }
            ans += yy.front() + yy.back();
            ans = ans * ((long double)h / 3);
            cout << "   Answer: " << ans << nn;
        }
        else if(t == 3)
        {
            ans = 0;
            for(j=1; j<yy.size()-1; j++)
            {
                if(j % 3 == 0) ans += (2 * yy[j]);
                else ans += (3 * yy[j]);
            }
            ans += yy.front() + yy.back();
            ans = ans * ((long double)(3*h) / 8);
            cout << "   Answer: " << ans << nn;
        }
        cout << nn;
    }



    return 0;
}


/*
9
0 1
0.125 0.8889
0.250 0.8000
0.375 0.7273
0.5 0.66667
0.625 0.6154
0.750 0.5714
0.875 0.5333
1.0 0.5
*/
