#include <bits/stdc++.h>
using namespace std;

int* to_binary(int n)
{
    int* arr = new int[8];
    for(int i=0; i<8; i++)
        arr[i]=0;
    int c=7;
    while(n!=0)
    {
        arr[c] = n%2;
        n = n/2;
        c--;
    }
    return arr;
}

int main()
{
    string a, b;
    cin >> a >> b;
    for(int i=0; i<a.size(); i++)
    {
        int str1 = a[i], str2 = b[i];
        int* arr1 = new int[8];
        int* arr2 = new int[8];
        int* arr3 = new int[8];
        arr1 = to_binary(str1);
        arr2 = to_binary(str2);
        for(int j=0; j<8; j++)
        {
            if(arr1[j] == arr2[j])
                arr3[j] = 0;
            else
                arr3[j] = 1;
        }
        int decimal = 0;
        for(int j=0; j<8; j++)
            decimal = decimal + int(pow(2,7-j))*arr3[j];
        if(decimal%26!=0)
            decimal=decimal%26;
        printf("%c",decimal+96);
    }
    return 0;
}

