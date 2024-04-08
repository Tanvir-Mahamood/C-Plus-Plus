#include<bits/stdc++.h>
using namespace std;

void linearSearch(int arr[],int n,int x)
{
    cout<<"Applying Linear Search:\n";
    int flag=0;
    for(int i=0;i<n;i++)
    {
        if(arr[i]==x)
        {
            cout<<"Found at the index no: "<<i<<endl;
            flag=1;
        }
    }
    if(flag==0) cout<<"Not found\n";
}

void binarySearch(int arr[],int n,int x)
{
    cout<<"Applying Binary Search:\n";
    int i,Beg,End,Mid,res=-1;
    sort(arr,arr+n);
    Beg=0;
    End=n-1;
    while(End>=Beg)
    {
        Mid=Beg+(End-Beg)/2;
        if(arr[Mid]==x)
        {
            res=Mid;
            break;
        }
        else if(arr[Mid]<x) Beg=Mid+1;
        else End=Mid-1;
    }
    if(res<0) cout<<"Not found.\n";
    else cout<<"Found at index "<<res<<endl;
}

int main()
{
    int n,i,x;
    cout<<"How many numbers?\n";
    cin>>n;
    int arr[n];
    cout<<"Enter elements: ";
    for(i=0;i<n;i++)
    {
        cin>>arr[i];
    }
    cout<<"Enter an element for searching: ";
    cin>>x;

    linearSearch(arr,n,x);
    binarySearch(arr,n,x);


    return 0;
}

