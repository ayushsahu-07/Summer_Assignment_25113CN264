//Write a program to Merge arrays

#include<iostream>
using namespace std;

int main(){
    int n,m;

    cout<<"Enter the size of array1: ";
    cin>>n;

    int a[n];
    cout<<"Enter the elements: ";
    for (int i = 0; i < n; i++)
    {
        cin>>a[i];
    }

    cout<<"Enter the size of array2: ";
    cin>>m;
    int b[m];
    cout<<"Enter the elements: ";
    for (int i = 0; i < m; i++)
    {
        cin>>b[i];
    }
    
    int merged[n + m];

    for (int i = 0; i < n; i++)
    {
        merged[i] = a[i];
    }
    
    for (int i = 0; i < m; i++)
    {
        merged[n + i] = b[i];
    }
    
    cout<<"Merged Array: ";
    for (int i = 0; i < n + m; i++)
    {
        cout<<merged[i]<<" ";
    }
    
    cout<<endl;

    return 0;
}