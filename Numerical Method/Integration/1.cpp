/*
Given a function y = 1 / (1+x).
Determine Integration of y.

Sample Input Output: Example 6.10 from the book Numerical Analysis by Sastry.
Enter lower limit and upper limit:0 1
Input Intervals, h: 0.125
Menu
   1. Trapezoidal Rule
   2. Simpson's 1/3
   3. Simpson's 3/8
 0. Exit

Enter choice: 1
   1. Trapezoidal Rule
   Answer: 0.694122

Enter choice: 2
   2. Simpson's 1/3
   Answer: 0.693155

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

long double get_y(long double x)
{
    //define a function here
    long double y = (long double)1 / (1+x);
    return y;
}

int main() {
    long double u, l, h, n,i, ans = 0; int j;
    vector<string> menu {"   1. Trapezoidal Rule", "   2. Simpson's 1/3", "   3. Simpson's 3/8", " 0. Exit"};

    cout << "Enter lower limit and upper limit:"; cin >> l >> u;
    cout << "Input Intervals, h: "; cin >> h;
    vector<long double> xx, yy;

    cout << "Menu\n";
    for(i=0; i<menu.size(); i++) cout << menu[i] << nn;
    cout << nn;

    i = l;
    while(i <= u)
    {
        xx.push_back(i);
        yy.push_back(get_y(i));
        i += h;
    }
    if(i-h != u)  //cout << u << nn;
    {
        xx.push_back(u);
        yy.push_back(get_y(u));
    }

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



