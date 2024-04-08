#include<bits/stdc++.h>
using namespace std;

void bubleSort(int arr[],int n)
{
    cout<<"Applying Bubble Sort: ";
    int temp,i,j;
    for(i=0;i<n-1;i++)
    {
        for(j=i+1;j<n;j++)
        {
            if(arr[i]>arr[j])
            {
                temp=arr[i];
                arr[i]=arr[j];
                arr[j]=temp;
            }
        }
    }
    for(i=0; i<n; i++) cout<<arr[i]<<" ";
    cout<<endl;
}

void insertionSort(int arr[],int n)
{
    cout<<"Applying Insertion Sort: ";
    int i,j,item;
    for(i=1;i<n;i++)
    {
        item=arr[i];
        j=i-1;
        while(j>=0 && arr[j]>item)
        {
            arr[j+1]=arr[j];
            j--;
        }
        arr[j+1]=item;
    }
    for(i=0; i<n; i++) cout<<arr[i]<<" ";
    cout<<endl;
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

    bubleSort(arr,n);
    insertionSort(arr,n);

    return 0;
}

