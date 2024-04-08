/*
Given some cards. Sort them using Merge Sort.
Each card contains suit(C, D, H, S) and Rank(2, 3, 4, 5, 6, 7, 8, 9, 10, J, Q, K, A)

Sample Input output:
11
C 1
D 5
C 5
C A
H A
H 10
S 7
S A
S J
D K
C Q

Sorted array:
C 1
D 5
C 5
S 7
H 10
S J
C Q
D K
C A
H A
S A
*/

#include <bits/stdc++.h>
using namespace std;
#define nn  "\n"

void Merge(vector<pair<int,char>>& arr, int left, int mid, int right)
{
    int n1 = mid - left + 1;
    int n2 = right - mid;

    vector<pair<int,char>> leftArray(n1);
    vector<pair<int,char>> rightArray(n2);

    for(int i = 0; i < n1; i++) leftArray[i] = arr[left + i];
    for(int j = 0; j < n2; j++) rightArray[j] = arr[mid + 1 + j];

    int i = 0; // Initial index of first sub-array
    int j = 0; // Initial index of second sub-array
    int k = left; // Initial index of merged sub-array

    while(i < n1 && j < n2) //careful
    {
        if (leftArray[i].first <= rightArray[j].first) arr[k] = leftArray[i++];
        else arr[k] = rightArray[j++];
        k++;
    }

    // remaining elements
    while (i < n1)
    {
        arr[k] = leftArray[i];
        i++;
        k++;
    }
    while (j < n2)
    {
        arr[k] = rightArray[j];
        j++;
        k++;
    }
}

void mergeSort(vector<pair<int,char>>& arr, int left, int right)
{
    if (left < right)
    {
        int mid = left + (right - left) / 2;

        mergeSort(arr, left, mid);
        mergeSort(arr, mid + 1, right);

        Merge(arr, left, mid, right);
    }
}

void printArray(const vector<pair<int,char>>& arr)
{
    for (pair<int,char> num : arr)
    {
        cout << num.second << " ";
        if(num.first == 11) cout << 'J';
        else if(num.first == 12) cout << 'Q';
        else if(num.first == 13) cout << 'K';
        else if(num.first == 14) cout << 'A';
        else cout << num.first;
        cout << nn;
    }
}

int main()
{
    int n, i, a, b; //nam fam
    char fam; string nam;
    cin >> n;
    vector<pair<int,char>> arr;
    for(i=0; i<n; i++)
    {
        cin >> fam >> nam;

        if(nam[0] == 'A') a = 14;
        else if(nam[0] == 'K') a = 13;
        else if(nam[0] == 'Q') a = 12;
        else if(nam[0] == 'J') a = 11;
        else if(nam == "10") a = 10;
        else a = nam[0] - '0';

        arr.push_back({a, fam});
    }

    mergeSort(arr, 0, n - 1);

    cout << "\nSorted array:" << std::endl;
    printArray(arr);

    return 0;
}
/*
11
C 1
D 5
C 5
C A
H A
H 10
S 7
S A
S J
D K
C Q
*/




