//Write a program to Find row-wise sum

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
    
    cout<<"\nRow-wise sum"<<endl;
    for (int i = 0; i < r; i++)
    {
        int sum = 0;
        for (int j = 0; j<c; j++)
        {
            sum +=A[i][j];
        }
        cout<<"Sum of row"<<i + 1<< " = "<<sum<<endl;
    }

    return 0;
}