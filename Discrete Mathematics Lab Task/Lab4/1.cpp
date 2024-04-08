#include<bits/stdc++.h>
using namespace std;

int MAXelement(int arr[],int n)
{
    int maxx=0;
    for(int i=0;i<n;i++)
    {
        if(arr[i]>maxx) maxx=arr[i];
    }
    return maxx;
}

int main()
{
    int n,i;
    cout<<"How many numbers?\n";
    cin>>n;
    int arr[n];
    cout<<"Enter elements: ";
    for(i=0;i<n;i++)
    {
        cin>>arr[i];
    }

    cout<<"Maximum number is: "<<MAXelement(arr,n)<<endl;

    return 0;
}
