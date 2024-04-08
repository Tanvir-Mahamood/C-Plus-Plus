//In the name of Allah, the Gracious, the Merciful
#include <bits/stdc++.h>
#define nn "\n"
#define ll long long
#define ull unsigned long long
using namespace std;
//from HH:MM:SS AM/PM to HH:MM:SS
/* Sample:
01:32:09PM
13:32:09
*/

string International(string s)
{
    int h;
    string hours;
    if(s[0]=='1' && s[1]=='2' && s[8]=='A')
    {
        s[0]='0';
        s[1]='0';
    }
    else if(s[0]=='1' && s[1]=='2' && s[8]=='P') {}
    else if(s[8]=='P')
    {
        h=(s[0]-48)*10+(s[1]-48);
        h+=12;
        hours=to_string(h);

        s[0]=hours[0];
        s[1]=hours[1];
    }
    s.pop_back();
    s.pop_back();
    return s;
}

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(0);
    string s1,s2;
    cin>>s1;
    s2=International(s1);
    cout<<s2<<nn;

    return 0;
}

