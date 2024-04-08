//Naive String Matching
#include<bits/stdc++.h>
using namespace std;
int main()
{
    string text,pattern;
    cout<<"Enter text: ";
    cin>>text;
    cout<<"Enter pattern: ";
    cin>>pattern;

    int n=text.length();
    int m=pattern.length();
    int s,j;
    for(s=0;s<=n-m;s++)
    {
        j=0;
        while(j<m && pattern[j]==text[s+j])
        {
            j++;
        }
        if(j==m)
        {
            cout<<"Pattern matched\n";
            break;
        }
    }
    cout<<"Pattern does not matched\n";

    return 0;
}
