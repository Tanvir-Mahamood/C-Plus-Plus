/*
Numerical methods for finding solution of Ordinary Differential Equation.
I've used Euler's Method and Modified Euler's method.

Problem: Example 8.7 from the book Numerical Analysis by Sastry.
Determine the value of y, when x = 0.1 and given,
    y(0) = 1 and y' = x^2+y; Take h as 0.05.
    Initial Guess: x0 = 0 and y0 = 1.
*/

#include <bits/stdc++.h>
using namespace std;
#define nn  "\n"
#define ll  long long

double target_x, h;

double Function(double x, double y) // Describe yourself.
{
    return (x*x + y);
    //return -y;
}

double Euler(double x, double y)
{
    while(x < target_x)
    {
        y = y + h * Function(x, y);
        x += h;
    }
    return y;
}

double Modified_Euler(double x, double y)
{
    while(x < target_x)
    {
        double past_x = x;
        double past_y = y;

        y = past_y + h*Function(past_x, past_y);
        x += h;

        y = past_y + (h / 2) * (Function(x, y) + Function(past_x, past_y));
    }
    return y;
}


int main() {
    double x, y;
    cout << "Enter initial guess of x and y:";
    cin >> x >> y;
    cout << "Enter target value of x:";
    cin >> target_x;
    cout << "Enter h:";
    cin >> h;

    cout << "Euler: " << Euler(x, y) << nn;
    cout << "Modified Euler: " << Modified_Euler(x, y) << nn;

    return 0;
}



