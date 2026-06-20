//Write a program to Check symmetric matrix

#include<iostream>
using namespace std;

int main(){
    int n;
    cout<<"Enter the size of square matrix: ";
    cin>>n;

    int A[10][10];
    cout<<"Enter elements of matrix:"<<endl;
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < n; j++)
        {
            cin>>A[i][j];
        }
    }
    
    int isSymmetric = 1;
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < n; j++)
        {
            if (A[i][j] != A[j][i])
            {
                isSymmetric = 0;
                break;
            }
        }
        if (isSymmetric == 0)
        {
            break;
        }
    }
    if (isSymmetric == 1)
    {
        cout<<"The matrix is symmetric."<<endl;
    }
    else
    {
        cout<<"The matrix is not symmetric"<<endl;
    }
    
    return 0;
}