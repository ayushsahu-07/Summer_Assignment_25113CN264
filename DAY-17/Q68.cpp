//Write a program to Find common elements

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

    cout<<"Common Elements: ";
    int count = 0;

    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < m; j++)
        {
            if (a[i] == b[j])
            {
                cout<<a[i]<<" ";
                count++;
                break;
            }
        }
    }
    
    if (count == 0)
    {
        cout<<"No common elements";
    }
    
    cout<<endl;

    return 0;
}