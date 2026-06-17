//Write a program to Union of arrays.

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

    int uni[n + m];
    int k = 0;

    for (int i = 0; i < n; i++)
    {
        uni[k++] = a[i];
    }
    
    for (int i = 0; i < m; i++)
    {
        int found = 0;
        for (int j = 0; j < n; j++)
        {
            if (b[i] == a[j])
            {
                found = 1;
                break;
            }
        }
        if (found == 0)
        {
            uni[k++] = b[i];
        }
        
    }
    
    cout<<"Union: ";
    for (int i = 0; i < k; i++)
    {
        cout<<uni[i]<<" ";
    }
    
    cout<<endl;

    return 0;
}