//Write a program to Reverse array

#include<iostream>
using namespace std;

int main(){
    int n, temp;
    cout<<"Enter the size of array: ";
    cin>>n;

    int arr[n];
    cout<<"Enter "<<n<<" element: ";
    for (int i = 0; i < n; i++)
    {
        cin>>arr[i];
    }
    cout<<"Original: ";
    for (int i = 0; i < n; i++)
    {
        cout<<arr[i]<<" "<<endl;
    }

    
    int start = 0, end = n-1;
    while (start < end)
    {
        temp = arr[start];
        arr[start] = arr[end];
        arr[end]= temp;
        start++;
        end--;
    }
    
    cout<<"Reverse: ";
    for (int i = 0; i < n; i++)
    {
        cout<<arr[i]<<" ";
    }
    
    return 0;
}