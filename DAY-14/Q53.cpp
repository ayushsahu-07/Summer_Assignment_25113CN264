//Write a program to Linear search

#include<iostream>
using namespace std;

int main(){
    int n, search;
    cout<<"Enter the size of array: ";
    cin>>n;

    int arr[n];

    cout<<"Enter "<<n<<" elements:"<<endl;
    for (int i = 0; i < n; i++)
    {
        cin>>arr[i];
    }
    cout<<"Enter the element to search: "<<endl;
    cin>>search;

    int index = -1;

    for (int i = 0; i < n; i++)
    {
        if (arr[i] == search)
        {
            index = i;
            break;
        }
        
    }
    
    if (index != -1)
    {
        cout<<"Element "<<search<<" found at index "<<index<<endl;
    }
    else
    {
        cout<<"Element "<<search<<" not found"<<endl;
    }
    
    return 0;
}