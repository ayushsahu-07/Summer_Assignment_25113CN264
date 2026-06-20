//Write a program to Find column-wise sum

#include<iostream>
using namespace std;

int main(){
    int r, c;
    cout<<"Enter row and column: ";
    cin>>r>>c;

    int A[10][10];
    cout<<"Enter the elements of matrix:"<<endl;
    for (int i = 0; i < r; i++)
    {
        for (int j = 0; j < c; j++)
        {
            cin>>A[i][j];
        }
    }
    
    cout<<"\nColumn-wise sum"<<endl;
    for (int j = 0; j < c; j++)
    {
        int sum = 0;
        for (int i = 0; i < r; i++)
        {
            sum +=A[i][j];
        }
        cout<<"Sum of column"<<j + 1<< " = "<<sum<<endl;
    }

    return 0;
}