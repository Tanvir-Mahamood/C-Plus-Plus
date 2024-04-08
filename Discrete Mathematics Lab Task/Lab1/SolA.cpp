#include <bits/stdc++.h>
using namespace std;

int main()
{
    int a, b;
    cin >> a >>b;

    if(a==1 || b==1) cout << 1 << endl; //Or Operation
    else cout << 0 << endl;

    if(a==1 && b==1) cout << 1 << endl; //And Operation
    else cout << 0 << endl;

    if(a==b) cout << 0 << endl; //Xor Operation
    else cout << 1 << endl;

    return 0;
}

