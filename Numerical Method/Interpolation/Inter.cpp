#include <bits/stdc++.h>
using namespace std;
#define nn  "\n"

long double p, m = 1;

long double get_p_for(int k)
{
    k--;
    long double ans = m*(p - k);
    m = ans;
    return ans;
}

long double get_p_bac(int k)
{
    k--;
    long double ans = m*(p + k);
    m = ans;
    return ans;
}

int Fact(int n)
{
    if(n == 0) return 1;
    return n * Fact(n-1);
}

void Newton_For(vector<vector<long double>> &grid, long double p, int n)
{
    long double y = grid[0][0];
    for(int i=1; i<n; i++) // formula of y
    {
        y += ((long double)get_p_for(i) / Fact(i) ) * grid[0][i];
    }
    cout << y << nn;
}

void Newton_Bac(vector<vector<long double>> &grid, long double p, int n)
{
    long double y = grid[n-1][0];
    for(int i=1; i<n; i++)
    {
        y += ((long double)get_p_bac(i) / Fact(i) ) * grid[n-1-i][i];
    }
    cout << y << nn;
}

void Gauss(vector<vector<long double>> &grid, long double p, int comm, int n)
{
    int midd = n / 2;
    long double factor, term;
    long double y = grid[midd][0];
    if(comm == 1)
    {
        for(int i=1; i<n; i++) // formula of y
        {
            factor = (long double)(p + 1) / (p - i + 1);
            term = ((long double)get_p_for(i) / Fact(i) ) * grid[(n-i)/2][i]; //cout << term << " ";
            if(i >=  3) term *= factor;
            y += term;
        }
    }
    else
    {
        for(int i=1; i<n; i++) // formula of y
        {
            factor = (long double)(p - 1) / (p + i - 1);
            term = ((long double)get_p_bac(i) / Fact(i) ) * grid[(n-i-1)/2][i];
            if(i >=  3) term *= factor;
            y += term;
        }
    }
    cout << y << nn;
}

//void Lagrange(vector<vector<long double>> &grid, long double xx[], int n, long double x)
//{
//    long double lob, hor, term, y;
//
//    for(int i=0; i<n; i++)
//    {
//        lob = hor = 1;
//        for(int j=0; j<n; j++)
//        {
//            if(i == j) continue;
//            lob *= (x - xx[j]);
//            hor *= (xx[i] - xx[j]);
//        }
//        term = (long double)lob / hor * grid[i][0];
//        y += term;
//    }
//    cout << y << nn;
//}


int main()
{
    int n, i, j, t = 100, midd;
    long double  val_x, val_y, h, x, y, lob, hor, term;

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
    h = xx[1] - xx[0];

    for(j=1; j<n; j++) //table ready
    {
        for(i=0; i<n-1; i++)
        {
            grid[i][j] = grid[i+1][j-1] - grid[i][j-1];
        }
    }

    cout << "Enter desired value of x: ";
    cin >> x;

    vector<string> menu {"   1. Newton's Forward", "   2. Newton's backward", "   3. Gauss", "   4. Lagrange", "   0. Exit"};
    for(i=0; i<5; i++) cout << menu[i] << nn;

    while(t != 0)
    {
        cout << "\n Enter your choice : ";
        cin >> t;
        if(t) cout << " Applying " << menu[t-1] << nn;

        if(t == 1)
        {
            m = 1;
            p = (long double)(x - xx[0]) / h;
            Newton_For(grid, p, n);
        }
        else if(t == 2)
        {
            m = 1;
            p = (long double)(x - xx[n-1]) / h;
            Newton_Bac(grid, p, n);
        }
        else if(t == 3)
        {
            m = 1;
            int comm;
            if(x >= xx[midd]) comm = 1; //forward
            else comm = 0; //bacward
            p = (long double)(x - xx[midd]) / h;
            Gauss(grid, p, comm, n);
        }
        else if(t == 4)
        {
            //Lagrange(grid, xx, n, x);
            //cout << "gl";
            y = 0;
            for(i=0; i<n; i++)
            {
                lob = hor = 1;
                for(j=0; j<n; j++)
                {
                    if(i == j) continue;
                    lob *= (x - xx[j]);
                    hor *= (xx[i] - xx[j]);
                }
                term = (long double)lob / hor * grid[i][0];
                y += term;
            }
            cout << y << nn;
        }
    }

    return 0;
}

/*
4
1 24
3 120
5 336
7 720
*/





