//Write a program to Frequency of an element

#include<iostream>
using namespace std;

int main(){
    int n, search, count = 0;

    cout<<"Enter size of array: ";
    cin>>n;

    int arr[n];
    cout<<"Enter "<<n<<" elements: ";
    for (int i = 0; i < n; i++)
    {
        cin>>arr[i];
    }
    cout<<"Enter element to find frequency: ";
    cin>>search;
    
    for (int i = 0; i < n; i++)
    {
        if (arr[i]==search)
        {
            count++;
        }
        
    }
    if (count == 0)
    {
        cout<<"Element"<<search<<"not found"<<endl;
    }
    else{
        cout<<"Frequency of "<<search<<" is "<<count<<endl;
    }
    return 0;
}