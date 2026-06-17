//Write a program to Intersection of arrays

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

    int inter[n + m], k = 0;

    for (int i = 0; i < n; i++)
    {
        int found = 0;
        for (int j = 0; j < m; j++)
        {
            if (a[i] == b[j])
            {
                found = 1;
                break;
            }
        }
        if (found == 1)
        {
            inter[k++] = a[i];
        }
    }

    cout<<"Intersection: ";
    for (int i = 0; i < k; i++)
    {
        cout<<inter[i]<<" ";
    }
    cout<<endl;
    
    return 0;
}