#include <bits/stdc++.h>
using namespace std;

#define nn  '\n'
#define ll  long long
double Error = 0.0001;
vector<int> arr;

double Function(double x)
{
    int i, power = arr.size() - 1;
    double y = 0;
    for(i=0; i<arr.size(); i++)
        y += arr[i] * pow(x,power-i);

    return y;
}

double Diff_Function(double x) //Differential Function
{
    int i, power = arr.size() - 1;
    double y = 0;
    for(i=0; i<arr.size(); i++)
        y += (power - i) * arr[i] * pow(x, power - 1 - i);

    return y;
}

double Phy(double x) //Predefined Function for Iterative method
{
    //f(x) = x^3 - 2x - 5.
    //phy(x) = (2x+5)^1/3
    double y = pow(2*x+5, 1.0/3.0);
    return y;
}

void adj(double *a, double *b) //Adjust the value of a and b for first 2 methods
{
    ll i, present, past, fact;

    past = Function(-101);       *a = -101;
    for(i=-100; i<=100; i++)
    {
        present = Function(i);   *b = i;
        fact    = present * past;
        if(present == 0) continue;
        if(fact < 0)     break;
        past    = present;       *a = i;
    }
}

void Bi_False(int t) //Bisection + False Position
{
    cout << fixed << setprecision(10);
    cout << " N             a                b                x                E\n\n";

    double a , b , x, past, present;
    adj(&a, &b);
    int cnt = 1;

    if(t == 1) x = (double)(a+b) / 2;
    else       x = (double)(a * Function(b) - b * Function(a)) / (Function(b) - Function(a));

    cout << " " << cnt << "       " << a << "       " << b << "       " << x << nn;

    while(1)
    {
        past = x;
        cnt++;

             if(Function(a)*Function(x) < 0) b = x;
        else if(Function(a)*Function(x) > 0) a = x;
        else break;

        if(t == 1) x = (double)(a+b) / 2;
        else       x = (double)(a * Function(b) - b * Function(a)) / (Function(b) - Function(a));
        present = x;

        cout << " " << cnt << "       " << a << "       " << b << "       " << x << "       " << abs(present - past) << nn;

        if(abs(present - past) < Error) break;
    }
    cout << fixed << setprecision(4);
    cout << " Final Ans: " << x << nn;
    cout << " Number of Iteration: " << cnt << nn << nn;
}

void Newton()
{
    cout << fixed << setprecision(10);
    cout << " N             x_n                x_n+1                E\n\n";

    double past, present, x = 1;
    if(Function(x) == 0 || Diff_Function(x) == 0) x++;

    past = x;
    int cnt = 1;
    x = x - (double)(Function(x)) / Diff_Function(x);

    cout << " " << cnt << "       " << past << "       " << x <<nn;

    while(1)
    {
        past = x;
        cnt++;
        x = x - (double)(Function(x)) / Diff_Function(x);
        present = x;
        cout << " " << cnt << "       " << past << "       " << present << "       " << abs(present - past) <<nn;
        if(abs(present - past) < Error) break;
    }
    cout << fixed << setprecision(4);
    cout << " Final Ans: " << x << nn;
    cout << " Number of Iteration: " << cnt << nn << nn;
}

void Iterative()
{
    cout << fixed << setprecision(10);
    cout << " N             x_n                x_n+1                E\n\n";
    double present, past, x = 1;
    //if(answer != 0.0) x = floor(answer);
    past = x;
    int cnt = 1;
    x = Phy(x);
    cout << " " << cnt << "       " << past << "       " << x <<nn;

    while(1)
    {
        past = x;
        cnt++;
        x = Phy(x);
        present = x;
        cout << " " << cnt << "       " << past << "       " << present << "       " << abs(present - past) <<nn;
        if(abs(present - past) < Error) break;
    }
    cout << fixed << setprecision(4);
    cout <<" Final Ans: " << x << nn;
    cout << " Number of Iteration: " << cnt << nn << nn;
}

void Secant()
{
    cout << fixed << setprecision(9);
    cout << " N           X(i-1)              X(i)              X              E\n\n";

    double x, past, present;
    int cnt = 1;
    adj(&past, &present);

    while(abs(present - past) > Error)
    {
        x = (double)(past * Function(present) - present * Function(past)) / (Function(present) - Function(past));
        cout << " " << cnt << "       " << past << "       " << present << "       " << x << "       " << abs(present - past) << nn;
        past    = present;
        present = x;
        cnt++;
    }
    cout << fixed << setprecision(4);
    cout <<" Final Ans: " << x << nn;
    cout << " Number of Iteration: " << cnt - 1 << nn << nn;
}

int main()
{
    int t = 100, n, i, val;
    cout << " Input Coefficient of Polynomial Equation:\n";
    cout << " Enter Highest degree :";
    cin >> n;

    cout << " Enter co-efficient: ";
    for(i=0; i<n+1; i++)
    {
        cin >> val;
        arr.push_back(val);
    }
    cout << " Polynomial Equation:       " ;
    for(i=0; i<n+1; i++)
    {
        cout << arr[i] << "x^" << n - i;
        (i == n) ? cout << " = 0\n" : cout << " + ";
    }

    vector<string> menu {"   1. Bisection Method", "   2. False Position Method", "   3. Iteration Method", "   4. Newton-Raphson Method", "   5. Secant Method ",  "   0. Exit"};
    for(i=0; i<6; i++) cout << menu[i] << nn;

    while( t != 0 )
    {
        cout << "\n Enter your choice : ";
        cin >> t;
        if(t) cout << " Applying " << menu[t-1] << nn;

        if(t == 1 || t == 2) Bi_False(t); //Bisection + False Position
        else if(t == 3)      Iterative();
        else if(t == 4)      Newton();
        else if(t == 5)      Secant();
    }

    return 0;
}








