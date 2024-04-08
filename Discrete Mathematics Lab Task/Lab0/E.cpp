#include <bits/stdc++.h>
using namespace std;

int length(string s)
{
    int n = s.size();
    unordered_set<char> seen;
    int left = 0, right = 0, ans = 0;
    while (left < n && right < n)
    {
        if (seen.find(s[right]) == seen.end())
        {
            seen.insert(s[right++]);
            ans = max(ans, right - left);
        }
        else
        {
            seen.erase(s[left++]);
        }
    }
    return ans;
}

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(0);
    string str;
    cin>>str;
    int ans = length(str);
    cout << ans << endl;
    return 0;
}
