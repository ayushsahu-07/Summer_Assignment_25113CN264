//write a program to find diagonal sum.

#include<iostream>
using namespace std;

int main(){ss
    int n;
    cout<<"Enter size of square matrix: ";
    cin>>n;

    int a[n][n];

    cout<<"Enter elements of matrix:\n";
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < n; j++)
        {
            cin>>a[i][j];
        }
    }

    int diagonalSum = 0;

    for (int i = 0; i < n; i++)
    {
        diagonalSum += a[i][i];
    }

    cout<<"Matrix:\n";
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < n; j++)
        {
            cout<<a[i][j]<<" ";
        }
        cout<<"\n";
    }

    cout<<"Diagonal sum: "<<diagonalSum<<"\n";

    return 0;
}