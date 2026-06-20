//Write a program to Multiply matrices

#include<iostream>
using namespace std;

int main(){
    int rowA, rowB, colA, colB;

    cout<<"Enter row and column of matrix A: ";
    cin>>rowA>>colA;

    int A[10][10];
    cout<<"Enter the element of matrix A:"<<endl;
    for (int i = 0; i < rowA; i++)
    {
        for (int j = 0; j < colA; j++)
        {
            cin>>A[i][j];
        }
    }
    
    cout<<"Enter row and column of matrix B: ";
    cin>>rowB>>colB;

    int B[10][10];
    cout<<"Enter the element of matrix B:"<<endl;
    for (int i = 0; i < rowB; i++)
    {
        for (int j = 0; j < colB; j++)
        {
            cin>>B[i][j];
        }
    }

    if (colA != rowB)
    {
        cout<<"It is not possible";
        return 0;
    }
    
    int C[10][10];
    for (int i = 0; i < rowA; i++)
    {
        for (int j = 0; j < colB; j++)
        {
            C[i][j] = 0;
            for (int k = 0; k < colA; k++)
            {
                C[i][j] += A[i][k]*B[k][j];
            }
        }
    }

    cout<<"\nResultant matrix of C is:"<<endl;
    for (int i = 0; i < rowA; i++)
    {
        for (int j = 0; j < colB; j++)
        {
            cout<<C[i][j]<<"\t";
        }
        cout<<endl;
    }
    

    return 0;
}
