#include <iostream>
using namespace std;
int main()
{
    int r1,c1,r2,c2,row,col,ele,sum=0;
    cout<<"Enter row and collumn for Matrix A:";
    cin>>r1>>c1;
    cout<<"Enter row and collumn for Matrix B:";
    cin>>r2>>c2;
    if(c1 != r2)
    {
        cout<<"Error! Column of first matrix not equal to row of second matrix.";
        return 0;
    }

    int A[r1][c1],B[r2][c2],mul[r1][c2];

    //scaning matrix A
    cout<<"Enter the elements of Matrix A:\n";
    for(row=0; row<r1; row++)
    {
        for(col=0; col<c1; col++)
        {
            cin>>A[row][col];
        }
        cout<<"\n";
    }

    //scaning matrix B
    cout<<"Enter the elements of Matrix B:\n";
    for(row=0; row<r2; row++)
    {
        for(col=0; col<c2; col++)
        {
            cin>>B[row][col];
        }
        cout<<"\n";
    }

    //printing matrix A
    cout<<"A:\n";
    for(row=0; row<r1; row++)
    {
        cout<<"\t";
        for(col=0; col<c1; col++)
        {
            cout<<A[row][col]<<" ";
        }
        cout<<"\n";
    }

    //printing matrix B
    cout<<"B:\n";
    for(row=0; row<r2; row++)
    {
        cout<<"\t";
        for(col=0; col<c2; col++)
        {
            cout<<B[row][col]<<" ";
        }
        cout<<"\n";
    }

    //multilpication
    for(row=0; row<r1; row++)
    {
        for(col=0; col<c2; col++)
        {
            for(ele=0;ele<c1; ele++)
            {
                sum+=A[row][ele]*B[ele][col];
            }
            mul[row][col]=sum;
            sum=0;
        }
    }

    //Printing multiplication
    cout<<"Multiplication:\n";
    for(row=0; row<r1; row++)
    {
        cout<<"\t";
        for(col=0; col<c2; col++)
        {
            cout<<mul[row][col]<<" ";
        }
        cout<<"\n";
    }


    return 0;
}


