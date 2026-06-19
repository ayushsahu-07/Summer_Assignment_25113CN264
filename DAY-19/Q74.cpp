//Write a program to Subtract matrices

#include<iostream>
using namespace std;

int main(){
    int r,c;
    cout<<"Enter rows and columns: ";
    cin>>r>>c;

    int a[r][c], b[r][c], diff[r][c];

    cout<<"Enter elements of first matrix:\n";
    for (int i = 0; i < r; i++)
    {
        for (int j = 0; j < c; j++)
        {
            cin>>a[i][j];
        }
    }

    cout<<"Enter elements of second matrix:\n";
    for (int i = 0; i < r; i++)
    {
        for (int j = 0; j < c; j++)
        {
            cin>>b[i][j];
        }
    }
    
    for (int i = 0; i < r; i++)
    {
        for (int j = 0; j < c; j++)
        {
            diff[i][j] = a[i][j] - b[i][j];
        }
    }
    
    cout<<"Difference of matrices:\n";
    for (int i = 0; i < r; i++)
    {
        for (int j = 0; j < c; j++)
        {
            cout<<diff[i][j]<<" ";
        }
        cout<<"\n";
    }

    return 0;
}